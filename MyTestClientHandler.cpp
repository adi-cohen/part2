//
// Created by adi on 09/01/2020.
//

#include <sstream>
#include <sys/socket.h>
#include "MyTestClientHandler.h"
#include "string"

using namespace std;

void MyTestClientHandler::handleClient(int client_socket) {
    bool inFile = true;
    string firstBuffer = "";
    while (inFile) {
        char buffer[1024] = {0};
        read(client_socket, buffer, 1024);
        string secondBuffer = buffer;
        firstBuffer = firstBuffer + secondBuffer;
        string firstPart = firstBuffer.substr(0, firstBuffer.find("\n")); //all tha values from start to \n
        int startSecondPart = firstBuffer.find("\n") + 1;
        string secondPart = firstBuffer.substr(
                startSecondPart, firstBuffer.length()); //all the values from \n to end

        if (this->chacheMenager->find(firstPart)) {
            string solution = this->chacheMenager->get(firstPart);
            const char *solutionChar = solution.c_str();
            send(client_socket, solutionChar, solution.size(), 0);
        } else {
            string solution = this->solver->solve(firstPart);
            this->chacheMenager->save(firstPart, solution);
            const char *solutionChar = solution.c_str();
            send(client_socket, solutionChar, solution.size(), 0);
        }
        firstBuffer = secondPart;
        if (firstPart == "end") {
            //we finish the reading of the file
            inFile = false;
        }
    }

}
