#include "BloomFilter.h"

#include <string> 
#include <vector>
#include <cstdlib> 
#include <ctime> 

BloomFilter::BloomFilter(float p, int m, float c, float d){
    this->p = p;
    this->m = m;
    this->c = c;
    this->d = d;
    this->size = bloomFilterSize(p, m, c);
    this->hashFunctionCount = numHashFunctions(size, m, d);
    bloomfilter = new bool[size];
    hashtable = new HashTable(nextPrime(m/10));
    hashPrime = nextPrime(size);

    for (int i=0; i < hashFunctionCount; i++)
    {
        random();
    }
    // inserting 10000 elements, remove 1000 elements --> 10
}

void BloomFilter::random(){
    srand(time(NULL));
    int a = rand() % size;
    int b = rand() % size;

    randomVect.push_back({a, b});
}

void BloomFilter::insert(std::string element){
    unsigned int intElement = strToInt(element);

    for(int i = 0; i < hashFunctionCount; i++){
        int bloomIndex = hashFam(intElement, i);
        if(bloomfilter[bloomIndex] == false){
            bloomfilter[bloomIndex] = true;
        }
    }

    hashtable->remove(element);
}

void BloomFilter::remove(std::string element){
    hashtable->insert(element);
}

bool BloomFilter::find(std::string element){
    unsigned int intElement = strToInt(element);

    for(int i = 0; i < hashFunctionCount; i++){
        int bloomIndex = hashFam(intElement, i);
        if(bloomfilter[bloomIndex] == false){
            return false;
        }
    }

    if(hashtable->find(element) == true){
        return false;
        }
    else{
        return true;
        }
}

void BloomFilter::print(){
    
}

int BloomFilter::hashFam(unsigned int element, int index){
    int result;
    int a = randomVect[index].first;
    int b = randomVect[index].second;

    int biggerPrime = hashPrime;

    result = ((a * element + b) % biggerPrime) % size;
    return result;
}
