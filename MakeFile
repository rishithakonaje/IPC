CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lrt

all: sender receiver

sender: sender.cpp shared_data.h
	$(CXX) $(CXXFLAGS) sender.cpp -o sender $(LDFLAGS)

receiver: receiver.cpp shared_data.h
	$(CXX) $(CXXFLAGS) receiver.cpp -o receiver $(LDFLAGS)

clean:
	rm -f sender receiver# Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: sender receiver

sender: sender.cpp shared_data.h
	$(CXX) $(CXXFLAGS) sender.cpp -o sender

receiver: receiver.cpp shared_data.h
	$(CXX) $(CXXFLAGS) receiver.cpp -o receiver

clean:
	rm -f sender receiver

