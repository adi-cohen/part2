cmake_minimum_required(VERSION 3.15)
project(part2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(part2 main.cpp ClientHandler.h MyTestClientHandler.h Solver.h CacheManager.h Server.h
        MySerialServer.h MySerialServer.cpp ClientHandler.h mySocket.cpp
        mySocket.h Problem.h Solution.h StringReverser.h FileCacheManager.h ISearchable.h State.h
        Isearcher.h QueueSearcher.h CompareCost.h CompareCost.cpp StackSearcher.h PrioritySearcher.h BestFirstSearch.h
        DFS.h MatrixProblem.h MyClientHandler.h  AStar.h AStar.cpp MatrixSolverBestFS.h
        MyClientHandler.cpp BFS.h  myParallelServer.cpp myParallelServer.h)
