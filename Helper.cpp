//Helper.cpp

#ifndef HELPER_CPP
#define HELPER_CPP

#include "Helper.h"

#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>

int bloomFilterSize(float p, int m, float c){
    int n;
    n = c*-(m * log(p))/(pow(log(2), 2));
    return n;
}

int numHashFunctions(int n, int m, float d){
    int numHash; 
    numHash = (n * d * log(2))/m;
    return numHash;
}

unsigned int strToInt(std::string element){
    int C = 11; //maybe think about this a bit
    unsigned int x;
    for(int i = 0; i < element.length(); i++){
        x += (unsigned int)(element[i] * pow(C, i));
    }
    return x;
}

bool isPrime(int number){
    if (number <= 1){
        return false;
    }
    for (int i = 2; i < number; i++){
        if (number % i == 0){
            return false;
        }
    }
    return true;
}

int nextPrime(int n){
    int biggerPrime = n + 1;
    while(isPrime(biggerPrime) != true){
        biggerPrime++;
    }
    return biggerPrime;
}

#endif