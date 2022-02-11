//HashTable.cpp
#include "HashTable.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream> //?
#include <bits/stdc++.h>

int HashTable::getM(){
    return m;
}

HashTable::HashTable(int q){
    this->m = q;
    hashtable = new LinkedList[m];
}

void HashTable::insert(std::string element){
    unsigned int index = strToInt(element);
    int hashBucket = index % m;

    hashtable[hashBucket].appendWord(element);
}

void HashTable::remove(std::string element){
    unsigned int index = strToInt(element);
    int hashBucket = index % m;

    hashtable[hashBucket].deleteWord(element);
}

bool HashTable::find(std::string element){
    unsigned int index = strToInt(element);
    int hashBucket = index % m;

    return hashtable[hashBucket].find(element);
}

void HashTable::print() const{
    for(int i = 0; i < m; i++){
        hashtable[i].print();
        std::cout << std::endl;
    }
}