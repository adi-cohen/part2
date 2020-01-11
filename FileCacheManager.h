//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_FILECACHEMANAGER_H
#define PART2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include "map"

class FileCacheManager : public CacheManager {
private:
    map<string ,string > problemMap;
    int index = 0;
public:
    bool find(string problem) override;
    string get(string problem) override ;
    void save(string problem, string solution) override ;
    FileCacheManager();
};


#endif //PART2_FILECACHEMANAGER_H
