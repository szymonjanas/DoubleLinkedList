#pragma once
#include <memory>

template<typename T>
struct Node 
{
    Node() :
        value(0), next(nullptr), prev(nullptr) {}
    Node(T data) :
        value(data), next(nullptr), prev(nullptr) {}    
    T value;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;

};
