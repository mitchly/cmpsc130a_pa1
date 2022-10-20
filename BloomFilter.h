//BloomFilter.h

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include "HashTable.h"
#include "Helper.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <cstdlib> 
#include <ctime> 

class BloomFilter {
    public:
        BloomFilter(float p, int m, float c, float d);
        void random();
        void insert(std::string element);
        void remove(std::string element);
        bool find(std::string element);
        void print();
        int hashFam(unsigned int element, int index);
    private:
        float p;
        int m; //size of bloomfilter
        float c;
        float d;
        int hashPrime;
        int size;
        int hashFunctionCount;
        bool *bloomfilter;
        HashTable *hashtable;
        std::vector<std::pair<int, int>> randomVect;
};

#endif //BLOOMFILTER_H