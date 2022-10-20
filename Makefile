CMP = g++

CXXFLAGS = -g -std=c++17 -Wall

all: main.o HashTable.o Helper.o BloomFilter.o LinkedList.o
	$(CMP) $(CXXFLAGS) -o pa1 main.o HashTable.o Helper.o BloomFilter.o LinkedList.o

#HashTable: main.o HashTable.o Helper.o LinkedList.o
#	$(CMP) $(CXXFLAGS) -o pa1 main.o HashTable.o Helper.o LinkedList.o

run:
	./PA1 inputs/setup.txt inputs/input.txt inputs/successfulSearch.txt inputs/failedSearch.txt inputs/remove.txt

clean:
	rm -f *.o *.exes