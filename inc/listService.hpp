#pragma once
#include <memory>
#include <iostream>
#include <exception>
#include "main_exceptions.hpp"
#include "node.hpp"

using namespace std;

template<typename TT>
class List
{   
    shared_ptr<Node<TT>> head;
    shared_ptr<Node<TT>> tail;

    unsigned int listSize;

    void pushFirstNode(shared_ptr<Node<TT>> newNode) noexcept;
    void pushFrontWhenSizeIsOne(shared_ptr<Node<TT>> newNode) noexcept;
    void eraseElementWhenSizeIsOne(shared_ptr<Node<TT>> node) noexcept;
    
    public:
    List() :
        head(nullptr), tail(nullptr), listSize(0) {}

    shared_ptr<Node<TT>> getHead() const noexcept;
    shared_ptr<Node<TT>> getTail() const noexcept;
    unsigned int getListSize() const noexcept;
    shared_ptr<Node<TT>> getNode(unsigned int position) const;
    shared_ptr<Node<TT>> getBackward (TT data) const;

    void push_back(TT data) noexcept;
    void push_front(TT data) noexcept;
    void insert(TT value, unsigned int position);

    void pop_back();
    void pop_front();
    void erase_pos(unsigned int position);

    void show() const noexcept;
    void clear() noexcept;
};

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getHead() const noexcept
{
    return head;
}

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getTail() const noexcept
{
    return this->tail;
}

template<typename TT>
unsigned int List<TT>::getListSize() const noexcept
{
    return listSize;
}

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getNode(unsigned int position) const
{
    try
    {
        if (position > listSize or position < 1) throw pos_error;
        if (position == getListSize()) return tail;
        
        shared_ptr<Node<TT>> newNode = head;
        for (unsigned int i = 1; i < position; i++ )
        {
            newNode = newNode->next;
        }
        return newNode;
    }
    catch (WrongPositionGiven& ex)
    { 
        ex.what();
    }
    return 0;
}

template<typename TT>
shared_ptr<Node<TT>> List<TT>::getBackward (TT data) const
{
    shared_ptr<Node<TT>> node = tail;
    if(getListSize() == 0) return nullptr;
    for (unsigned int i = 0; i < getListSize(); i++)
    {
        if (node->value == data) return node;
        else 
            node = node->prev;
    }
    return nullptr;
}

template<typename TT>\
void List<TT>::pushFirstNode(shared_ptr<Node<TT>> newNode) noexcept
{
    if (getListSize() == 0)
    {
        head = newNode;
        tail = newNode;
    }
}

template<typename TT>
void List<TT>::push_back(TT data) noexcept
{
    shared_ptr<Node<TT>> newNode = make_shared<Node<TT>>(data);
    if (getListSize() == 0) pushFirstNode(newNode);
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

template<typename TT>
void List<TT>::pushFrontWhenSizeIsOne(shared_ptr<Node<TT>> newNode) noexcept
{
    if (getListSize() == 1) 
    {
        tail = head;
        newNode->next = tail;
        tail->prev = newNode;
        head = newNode;
    }
}

template<typename TT>
void List<TT>::push_front(TT data) noexcept
{
    shared_ptr<Node<TT>> newNode = make_shared<Node<TT>>(data);
   
    if (getListSize() == 0) pushFirstNode(newNode);
    else if (getListSize() == 1) pushFrontWhenSizeIsOne(newNode);
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    listSize++;
}

template<typename TT>
void List<TT>::insert(TT data, unsigned int position)
{
    try
    {
        if (position < 0 or position > getListSize()) throw pos_error;
        
        shared_ptr<Node<TT>> newNode = make_shared<Node<TT>>(data);
        auto node = getNode(position);
        shared_ptr<Node<TT>> spareNode;

        if (getListSize() == 0) pushFirstNode(newNode);
        else if (getListSize() == 1) pushFrontWhenSizeIsOne(newNode);
        else if (getListSize() > 1)
        {
            spareNode = node->prev;
            spareNode->next = newNode;
            node->prev = newNode;
            newNode->next = node;
            newNode->prev = spareNode;
        }
        listSize++;
    }
    catch (WrongPositionGiven& ex)
    { 
        ex.what();
    }
}

template<typename TT>
void List<TT>::eraseElementWhenSizeIsOne(shared_ptr<Node<TT>> node) noexcept
{
    if (getListSize() == 1) 
        {
            node = head;
            tail = nullptr;
            head = nullptr;
            node.reset();
        }
}

template<typename TT>
void List<TT>::pop_back()
{
        if (getListSize() == 0) return;
        
        shared_ptr<Node<TT>> node;
        
        if (getListSize() == 1) eraseElementWhenSizeIsOne(node);
        else
        {
            shared_ptr<Node<TT>> spareNode;
            node = tail->prev;
            node->next = nullptr;
            spareNode = tail;
            tail = node;
            spareNode.reset();
        }
        listSize--;

}

template<typename TT>
void List<TT>::pop_front()
{
    if (getListSize() == 0) return;
    
    shared_ptr<Node<TT>> node;
    if (getListSize() == 1) eraseElementWhenSizeIsOne(node);
    else
    {
        node = head;
        head = head->next;
        head->prev = nullptr;
        node.reset();
    }
    listSize--;

}

template<typename TT>
void List<TT>::erase_pos(unsigned int position)
{
    try
    {
        if (position < 1 or position > getListSize()) throw pos_error;
        if (getListSize() == 0) return;

        shared_ptr<Node<TT>> node, prevNode, nextNode;
        if (getListSize() == 1) eraseElementWhenSizeIsOne(node);
        else if (position > 1)
        {
            node = getNode(position);
            nextNode = node->next;
            prevNode = node->prev;
            nextNode->prev = prevNode;
            prevNode->next = nextNode;
            node.reset();
        }
        listSize--;
    }
    catch (WrongPositionGiven& ex)
    { 
        ex.what();
    }
}

template<typename TT>
void List<TT>::show() const noexcept
{
    if (getListSize() == 0) cout << "List is Empty!" << endl;
    else if (getListSize() == 1) cout << "List: \n" << getHead()->value << endl << endl;
    else if (getListSize() > 1)
    {
        cout << "List: " << endl;
        shared_ptr<Node<TT>> node = head;
        for (unsigned int i = 1; node != nullptr; i++, node = node->next)
            cout << "Nr " << i << ": " << node->value << endl;
    }
}

template<typename TT>
void List<TT>::clear() noexcept
{
    if (getListSize() == 0) cout << "List is Empty!" << endl;
    else if (getListSize() == 1) head.reset();
    else if (getListSize() > 1)
    {
        shared_ptr<Node<TT>> node = head->next;
        for (unsigned int i = getListSize(); i > 0; i--)
        {
            head.reset();
            head = node;
            if (i != 1) node = node->next;
        }
    }
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}
