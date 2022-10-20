// LinkedList.cpp

#include "LinkedList.h"
#include <iostream>

// constructor
LinkedList::LinkedList(){ 
    first = last = nullptr;
}

// copy constructor
LinkedList::LinkedList(const LinkedList& source){
    first = last = nullptr;
    Node* n = source.first;
    while(n){
        std::string value = n->str;
        appendWord(value);
        n = n->next;
    }
}

// destructor deletes all nodes
LinkedList::~LinkedList() {
    clear(first);
    first = nullptr;
}

// helper function (for the destructor)
void LinkedList::clear(Node* n){
    if(n == nullptr){
        return;
    }
    clear(n->next);
    delete n;
}

bool LinkedList::find(std::string value){ // FIX SEGFAULT!!!!
    if(first == nullptr){
        return false;
    }
    
    Node* curNode = first;
    while(curNode != nullptr){
        if(curNode->str == value){
            return true;
        }
        curNode = curNode->next;
    }
    return false;
}

// append function appends a node to the end of the linked list
void LinkedList::appendWord(const std::string &word){
    if(first == nullptr){
        first = new Node();
        last = first;
        first->str = word;
        first->next = nullptr;
    }
    else{
        Node *newNode = new Node();
        newNode->next = first;
        newNode->str = word;
        first = newNode;
    }
}

void LinkedList::deleteWord(const std::string &word){
    Node* previous = first; 
    if(first == nullptr){
        return;
    }
    Node* current = first->next;
    if(first->str == word){
        first = current;
        delete previous;
        return;
    }
    while(current != nullptr){
        if(current->str == word){
            previous->next = current->next;
            delete current;
            return;
        }
        else{
            previous = current;
            current = current->next;
        }
    }
}

void LinkedList::print() const {
    Node *n = first;
    std::cout << '[';
    while (n) {
        std::cout << n->str;
        if (n->next)
            std::cout << " ";
        n = n->next;
    }
    std::cout << ']';
}