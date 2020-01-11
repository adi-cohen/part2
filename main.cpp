#include <iostream>
#include "string"
#include "Solver.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"

//create new namespace boot with function main
namespace boot {
    class Main {
    public:
        int main(int port) {
            // create serial server as server
            server_side::Server *serialServer = new mySerialServer();
            // create string reverser as solver
            Solver<string,string> *stringRevers = new StringReverser();
            // create file cache as cache manager
            CacheManager *fileCache = new FileCacheManager();
            // create testClientHandler with string reverser and file cache
            ClientHandler *testClient = new MyTestClientHandler<string, string>(stringRevers, fileCache);
            serialServer->open(port, testClient);
        }
    };
}

int main(int argc, char *argv[]) {
    //int port = atoi(argv[0]);
    boot::Main main;
    main.main(8081);
};
