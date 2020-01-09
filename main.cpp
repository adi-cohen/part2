#include <iostream>
#include "string"
#include "Solver.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"

namespace boot {
    class Main {
    public:
        int main(int port) {
            server_side::Server *serialServer = new mySerialServer();
            Solver<string,string> *stringRevers = new StringReverser();
            CacheManager *fileCache = new FileCacheManager();
            ClientHandler *testClient = new MyTestClientHandler<string, string>(stringRevers, fileCache);
            serialServer->open(port, testClient);
        }
    };
}

int main(int argc, char *argv[]) {
    int port = atoi(argv[0]);
    boot::Main main;
    main.main(port);
};
