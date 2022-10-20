// LinkedList.h
// Linked list header file 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream> //?
#include <bits/stdc++.h>


class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList& source);
        bool find(std::string value);
        void appendWord(const std::string &word);
        void deleteWord(const std::string &word);
        void print() const; 
    private:
        struct Node{
            std::string str;
            Node* next;
        };
        void clear(Node* n);
        Node *first;
        Node *last;
};

#endif //LINKEDLIST