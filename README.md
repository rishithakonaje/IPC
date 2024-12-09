# IPC Project

Hey there! 👋 Welcome to my IPC (Inter-Process Communication) project. I put this together as a cahllenge by Dynon Avionics on how processes can chat with each other in C++. 
It's been a while since I've dived into this stuff, so bear with me if things aren't perfect!

## Project Requirements

- Language: C++
- Platform: Ubuntu 22.04
- Data Structure: Includes int, float, string, and enum types

## Implementation Details

The project consists of two main components:

1. Sender: Creates shared memory and writes data structures to it.
2. Receiver: Reads from the shared memory and displays the data.

## The Nitty-Gritty

How to Run This Thing : 
1. Clone this repo: 

              git clone https://github.com/rishithakonaje/IPC.git

2. Navigate to the project directory:

             cd IPC_project

3. Compile everything:

             make

4. Run the sender and receiver in one terminal(I prefer this way for no lag in data):

            ./sender & ./receiver

The receiver should print out 10 different versions of the data structure.

Technical Considerations
Shared memory is used for its efficiency in IPC.
The project demonstrates proper memory management and IPC resource handling.

Future Improvements
Implement error handling for robust production use.
Explore other IPC methods for comparison.

Wrapping Up
This project did dust off some old knowledge and learn a few new tricks!
