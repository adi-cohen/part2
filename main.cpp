#include <iostream>
#include "string"
#include "Solver.h"
#include "Server.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "FileCacheManager.h"
#include "MatrixSolverBestFS.h"
#include "Solver.h"
#include "Isearcher.h"
#include "ISearchable.h"
#include "BestFirstSearch.h"
#include "MyClientHandler.h"
//create new namespace boot with function main
namespace boot {
    class Main {
    public:
        int main(int port) {
            //create serial server as server
            server_side::Server *serialServer = new mySerialServer();

            //create file cache as cache manager
            CacheManager<string> *fileCache = new FileCacheManager<string>();

            //create testClientHandler with string reverser and file cache
            ClientHandler *clientHandler = new MyClientHandler(fileCache);
            serialServer->open(port, clientHandler);
        }
    };
}

int main(int argc, char *argv[]) {
    int port = atoi(argv[0]);
    boot::Main main;
    main.main(5600);
};
