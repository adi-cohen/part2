//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_CLIENTHANDLER_H
#define PART2_CLIENTHANDLER_H

#include "mySocket.h"


class ClientHandler {
public:
    virtual int handleClient(server_side:: mySocket, server_side:: mySocket out) = 0;
};


#endif //PART2_CLIENTHANDLER_H
