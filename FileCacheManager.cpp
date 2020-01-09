//
// Created by yaron on 08/01/2020.
//

#include <fstream>
#include "FileCacheManager.h"

bool FileCacheManager::find(string problem) {
    return problemMap.find(problem) != problemMap.end();
}

string FileCacheManager::get(string problem) {
    fstream myFile;
    string fileName = problemMap[problem];
    myFile.open(fileName,ios::in);
    if (!myFile.is_open()) {
        throw "an error - file not found";
    } else {
        string solution;
        myFile.read((char *) &solution, sizeof(solution));
        myFile.close();
        return solution;
    }

}

void FileCacheManager::save(string problem, string solution) {
    //create new index for new file
    this->index = index+1;
    //the file name is the number of the index
    string fileName = "problem number " + index;
    fstream io_file;
    //create new file
    io_file.open(fileName, ios::binary);
    if (!io_file.is_open()) {
        throw "error in opening the file";
    }
    //now insert to the file
    io_file.write((char *) &solution, sizeof(solution));
    io_file.close();
    //adding the file to the problemMap
    this->problemMap[problem] = fileName;

}
