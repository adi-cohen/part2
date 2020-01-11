//
// Created by adi on 08/01/2020.
//

#ifndef PART2_CACHEMANAGER_H
#define PART2_CACHEMANAGER_H

#include "string"
#include "list"
#include "unordered_map"
using namespace std;
template<typename P, typename S>
class CacheManager {

public:
    //we will get the problem
    virtual bool find(string problem) =0;
    virtual S get(string problem) = 0;
    virtual void save(string problem, S solution)=0;
};


#endif //PART2_CACHEMANAGER_H
