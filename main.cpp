#include "BloomFilter.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  if(argc <  6){
    cerr << "Usage: " << argv[ 0 ] << " setup.txt input.txt successfulSearch.txt failedSearch.txt remove.txt" << endl;
    exit(1);
  }

  ifstream setUp;
  ifstream input;
  ifstream successfulSearch;
  ifstream failedSearch;
  ifstream remove;
  
  setUp.open("./inputs/setup.txt");

  float p, c, d;
  int m;
  setUp >> p >> m >> c >> d;

  BloomFilter bestFriendsForever(p, m, c, d);
  std::string line;

  setUp.close();

  input.open("./inputs/input.txt");

  std::vector<std::string> inputs;
  for(int i = 0; i < 10000; i++){
    input >> line;
    inputs.push_back(line);
  }

  input.close();

  successfulSearch.open("./inputs/successfulSearch.txt");

  std::vector<std::string> success;
  for(int i = 0; i < 1000; i++){
    successfulSearch >> line;
    success.push_back(line);
  }

  successfulSearch.close();

  failedSearch.open("./inputs/failedSearch.txt");

  std::vector<std::string> fail;
  for(int j = 0; j < 1000; j++){
    failedSearch >> line;
    fail.push_back(line);
  }

  failedSearch.close();

  remove.open("./inputs/remove.txt");

  std::vector<std::string> removeWords;
  for(int k = 0; k < 1000; k++){
    remove >> line;
    removeWords.push_back(line);
  }

  remove.close();

  std::ofstream out("output 1.txt", std::fstream::app);

  int numFalsePos = 0;
  int numFalseNeg = 0;
  int totalFalsePos = 0;
  int totalFalseNeg = 0;

  for(int m = 0; m < 10; m++){
    for(int n = m * 1000; n < 1000 + m * 1000; n++){
      bestFriendsForever.insert(inputs[n]);
    }

    out << "Phase " << m << std::endl;
    out << "Number of false negatives: " << std::endl; // should be 0
    for(int n = m * 100; n < 100 + m * 100; n++){
      if(bestFriendsForever.find(success[n]) == false){
        numFalseNeg++;
        totalFalseNeg++;
      }
    }
    out << numFalseNeg << std::endl;
    numFalseNeg = 0;
    
    out << "Number of false positives:" << std::endl;
    for(int n = m * 100; n < 100 + m * 100; n++){
      if(bestFriendsForever.find(fail[n]) == true){
        numFalsePos++;
        totalFalsePos++;
      }
    }
    out << numFalsePos << std::endl;

    out << "Probability of false positives:" << std::endl;
    out << numFalsePos/100.0 << std::endl;
    numFalsePos = 0;

    out << "False Positive Elements:" << std::endl;
    for(int n = m * 100; n < 100 + m * 100; n++){
      if(bestFriendsForever.find(fail[n]) == true){
        out << fail[n] << std::endl;
      }
    }

    // remove
    for(int n = m * 100; n < 100 + m * 100; n++){
      bestFriendsForever.remove(removeWords[n]);
    }

    out << std::endl;
    out << "> > >" << std::endl;
    out << std::endl;
  }

  out << "Total Statistics:" << std::endl;
  out << "Number of false negatives:" << std::endl;
  out << totalFalseNeg << std::endl;
  out << "Number of false positives:" << std::endl;
  out << totalFalsePos << std::endl;
  out << "Probability of false positives:" << std::endl;
  out << totalFalsePos/1000.0 << std::endl;
  

  out.close();
}
