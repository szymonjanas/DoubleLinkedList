#pragma once
#include <memory>
//#include "listService.t.hpp"
#include <exception>
#include "main_exceptions.hpp"

using namespace std;

template<typename T>
struct Node 
{
    Node(int data) :
        value(data), next(nullptr), prev(nullptr) {}
    int value;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;

};

template<typename TT>
class List
{   
    shared_ptr<Node<TT>> head = nullptr;
    shared_ptr<Node<TT>> tail = nullptr;

    unsigned int listSize = 0;

    public:
    shared_ptr<Node<TT>> getHead() const;
    shared_ptr<Node<TT>> getTail() const;
    unsigned int getListSize() const;
    shared_ptr<Node<TT>> getNode(unsigned int position) const;
    
    
    void push_back(TT data);
  /*  void push_front(T data);
    void insert(T value, unsigned int position);
    
    void pop();
    void removeLast();
    void removePos(unsigned int position);
    void removeByValue(T value);
    */


};

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getHead() const
{
    return head;
}

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getTail() const
{
    return this->tail;
}

template<typename TT>
unsigned int List<TT>::getListSize() const
{
    return listSize;
}

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getNode(unsigned int position) const
{
    try
    {
        shared_ptr<Node<TT>> newNode = head;
        if (position < getListSize() or position < 1) throw pos_error;
        if (position == getListSize()) return tail;
        for (int i = 0; i < getListSize(); i++ )
        {
            newNode = newNode;
        }
        return newNode;
    }
    catch (WrongPositionGiven& ex)
    { 
        ex.what();
    }
}

template<typename TT>
void List<TT>::push_back(TT data)
{
    try
    {
        shared_ptr<Node<TT>> newNode = make_shared<Node<TT>>(data);
        newNode->next = nullptr;
        if (getListSize() < 0) throw pos_error;
        else if (getListSize() == 0)
        {
            newNode->prev = nullptr;
            head = newNode;
            tail = newNode;
        }
        else if (getListSize() == 1) 
        {
            newNode->prev = head;
            head->next = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }
    catch (WrongPositionGiven& ex)
    { 
        ex.what();
    }
}

