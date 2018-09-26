#pragma once
#include <memory>

template<typename T>
struct Node 
{
    Node() :
        value(0) {}
    Node(T data) :
        value(data) {}  
    ~Node(){}  
    T value;
    weak_ptr<Node> next;
    weak_ptr<Node> prev;

};
