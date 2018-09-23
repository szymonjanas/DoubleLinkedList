#pragma once
#include <memory>

using namespace std;

template<typename T>
struct listNode 
{
    listNode(int data) :
        value(data), next(nullptr), prev(nullptr) {}
    int value;
    shared_ptr<listNode> next;
    shared_ptr<listNode> prev;

};

template<typename TT>
class List
{   
    List() :
        head(nullptr), tail(nullptr), listSize(0) {}

    shared_ptr<listNode<TT>> head;
    shared_ptr<listNode<TT>> tail;

    unsigned int listSize;

    public:
    shared_ptr<listNode<TT>> getHead() const;
    shared_ptr<listNode<TT>> getTail() const;
    shared_ptr<listNode<TT>> getNode(unsigned int position) const;
    unsigned int getListSize() const;
    /*
    void push_back(T data);
    void push_front(T data);
    void insert(T value, unsigned int position);
    
    void pop();
    void removeLast();
    void removePos(unsigned int position);
    void removeByValue(T value);
    */
};
