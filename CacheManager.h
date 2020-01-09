//
// Created by adi on 08/01/2020.
//

#ifndef PART2_CACHEMANAGER_H
#define PART2_CACHEMANAGER_H

#include "string"
using namespace std;
class CacheManager {
public:
    virtual bool find(string problem) =0;
    virtual string get(string problem) = 0;
    virtual void save(string problem, string solution)=0;
};


#endif //PART2_CACHEMANAGER_H
