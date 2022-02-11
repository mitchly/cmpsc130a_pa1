#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <math.h>
#include <stdio.h>

int bloomFilterSize(float p, int m, float c);
int numHashFunctions(int n, int m, float d);
unsigned int strToInt(std::string element);
bool isPrime(int number);
int nextPrime(int n);

#endif