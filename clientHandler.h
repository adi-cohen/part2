//
// Created by adi on 08/01/2020.
//
#include "iostream"
using  namespace std;
#ifndef PART2_CLIENTHANDLER_H
#define PART2_CLIENTHANDLER_H

class clientHandler {
    virtual void handleClient(ifstream inputStream, ofstream outputtStream);
};

#endif //PART2_CLIENTHANDLER_H
