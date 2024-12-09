#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shared_data.h"

#define SHARED_MEMORY_NAME "/Data_Structure"
#define SHARED_MEMORY_SIZE sizeof(DataStructure)

const char* enumToString(DataType type) {
    switch (type) {
        case type1: return "type1";
        case type2: return "type2";
        case type3: return "type3";
        default: return "unknown";
    }
}

int main() {
    int shm_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    if (ftruncate(shm_fd, SHARED_MEMORY_SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    void* shared_mem = mmap(0, SHARED_MEMORY_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    DataStructure* data = static_cast<DataStructure*>(shared_mem);

    for (int i = 0; i < 10; ++i) {
        data->dataReady = false; 

        data->intValue = i;
        data->floatValue = i * 2;
        snprintf(data->stringValue, sizeof(data->stringValue), "Message %d", i);
        data->enumValue = static_cast<DataType>(i % 3);

        data->dataReady = true; 
        std::cout << "Sent: int=" << data->intValue
                  << ", float=" << data->floatValue
                  << ", string=" << data->stringValue
                  << ", enum=" << enumToString(data->enumValue) << std::endl;

        sleep(1);
    }

    munmap(shared_mem, SHARED_MEMORY_SIZE);
    shm_unlink(SHARED_MEMORY_NAME);

    return 0;
}
