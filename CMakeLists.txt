cmake_minimum_required(VERSION 3.15)
project(part2)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(part2 main.cpp ClientHandler.h MyTestClientHandler.h Solver.h CacheManager.h Server.h
        MySerialServer.h MySerialServer.cpp ClientHandler.h mySocket.cpp
        mySocket.h Problem.h Solution.h StringReverser.h FileCacheManager.h ISearchable.h State.h State.cpp
        Isearcher.h QueueSearcher.h CompareCost.h  StackSearcher.h PrioritySearcher.h BestFirstSearch.h
        DFS.h matrixProblem.h myParallelServer.cpp myParallelServer.h  BFS.h AStar.cpp AStar.h)
