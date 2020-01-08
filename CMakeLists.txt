cmake_minimum_required(VERSION 3.15)
project(part2)

set(CMAKE_CXX_STANDARD 11)

add_executable(part2 main.cpp ClientHandler.h myTestClientHandler.h Solver.h CachManager.h Server.h
        ClientHandler.cpp MySerialServer.h MySerialServer.cpp ClientHandler.cpp ClientHandler.h)