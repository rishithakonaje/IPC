#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "shared_data.h"

#define SHARED_MEMORY_NAME "/Data_Structure"
#define SHARED_MEMORY_SIZE sizeof(DataStructure)

//convert enum values to readable strings
const char* enumToString(DataType type) {
    switch (type) {
        case type1: return "type1";
        case type2: return "type2";
        case type3: return "type3";
        default: return "unknown";
    }
}

int main() {
    std::cout << "Receiver starting...\n";

    //open the shared memory
    int shm_fd = shm_open(SHARED_MEMORY_NAME, O_RDWR, 0666);
    if (shm_fd == -1) { 
        perror("shm_open failed in receiver"); //if receiver is run before sender 
        return 1;
    }
    std::cout << "Shared memory opened by receiver.\n";

    //handling mapping the region
    void* shared_mem = mmap(0, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed in receiver");
        return 1;
    }
    std::cout << "Shared memory mapped successfully.\n";

    // Cast the mapped region to shared data 
    DataStructure* data = static_cast<DataStructure*>(shared_mem);

    for (int i = 0; i < 10; ++i) {
        //flag if data is ready
        while (!data->dataReady) {
            usleep(1000); //semaphores might complicate
        }
        
        //received data print in readable form
        std::cout << "Received int: " << data->intValue
                  << ", float: " << data->floatValue
                  << ", string: " << data->stringValue
                  << ", enum: " << enumToString(data->enumValue) << std::endl;

        // Mark data for next entry
        data->dataReady = false; 
    }

    // Cleanup
    munmap(shared_mem, SHARED_MEMORY_SIZE);
    std::cout << "Receiver finished.\n";

    return 0;
}
