#include <netinet/in.h>
#include "MySerialServer.h"
#include "iostream"

//
// Created by yaron on 08/01/2020.
//
int mySerialServer::open(int port, ClientHandler* handler) {
    // create a socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        throw "Could not create a socket";
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        throw "Error during listening command";
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }


}

int mySerialServer::close() {

}
