//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_MYSOCKET_H
#define PART2_MYSOCKET_H
#include <string>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
namespace server_side {
     // the following class was created for saving the socket ID
    class mySocket {
    private:
        int socketID;
    public:
        mySocket(int id) {
            socketID = id;
        }
        // writing the solution(sthe string str) to the client:
        bool writeOut(std::string str) {
            int n = write(socketID, str.c_str(), str.size());
            // if the write was accomplished successfully:
            if (n > 0) {
                return true;
                // wasn't successful
            } else {
                return false;
            }
        }

        // the following method will read the socket data which is a string:
        bool readIn(std::string* str) {
            char buffer[BUFFER_SIZE];
            // zeroing the buffer
            ::bzero(buffer, BUFFER_SIZE);
            // reading the socket data to the buffer
            int n = read(socketID, buffer, BUFFER_SIZE - 1);
            buffer[BUFFER_SIZE - 1] = '\0';
            str->clear();
            // set the data of the buffer to the input string
            str->append(buffer);
            // if the read was accomplished successfully:
            if (n > 0) {
                return true;
                // wasn't successful
            } else {
                return false;
            }
        }
        // close the socket
        void close() {
            ::close(socketID);
        }
    };
}

#endif //PART2_MYSOCKET_H
