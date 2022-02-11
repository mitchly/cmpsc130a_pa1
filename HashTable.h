//HashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include "Helper.h"

#include <string>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

class HashTable {
    public:
        HashTable(int q);
        int getM();
        void insert(std::string element);
        void remove(std::string element);
        bool find(std::string element);
        void print() const;
    private:
        int m; // size of hashtable
        LinkedList *hashtable;
};

#endif //HASHTABLE