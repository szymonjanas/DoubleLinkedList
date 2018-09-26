#include <memory>
#include <iostream>

#include "main_exceptions.hpp"
#include "node.hpp"

using namespace std;

template<typename T>
class List
{
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;

    unsigned int listSize;

    bool push_first(shared_ptr<Node<T>>) noexcept;
    public:
    List():
        head(nullptr), tail(nullptr), listSize(0) {}
    
    ~List(){}

    shared_ptr<Node<T>> getHead() const noexcept;
    shared_ptr<Node<T>> getTail() const noexcept;
    unsigned int getListSize() const noexcept;
    shared_ptr<Node<T>> getNode(unsigned int position) const;
    shared_ptr<Node<T>> getBackward (T data) const;

    void push_back(shared_ptr<Node<T>>) noexcept;
    void push_front(shared_ptr<Node<T>>) noexcept;

    void pop_back();
    void pop_front();
    
    void show() const noexcept;
};

template<typename T>
shared_ptr<Node<T>> List<T>::getHead() const noexcept
{
    return head;
}

template<typename T>
shared_ptr<Node<T>> List<T>::getTail() const noexcept
{
    return tail;
}

template<typename T>
unsigned int List<T>::getListSize() const noexcept
{
    return listSize;
}

template<typename T>
shared_ptr<Node<T>> List<T>::getNode(unsigned int position) const
{
    if (position > listSize or position < 1) return nullptr;
    if (position == listSize) return tail;

    weak_ptr<Node<T>> node (head);
    for (unsigned int i = 1; i < position; i++ )
    {
        node = node.lock()->next;
    }
    return node.lock();

}

template<typename T>
bool List<T>::push_first(shared_ptr<Node<T>> node) noexcept
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
        return false;
    }
    else return true;
}

template<typename T> 
void List<T>::push_back(shared_ptr<Node<T>> node) noexcept
{
    if (push_first(node))
    {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    listSize++;
}

template<typename T>
void List<T>::push_front(shared_ptr<Node<T>> node) noexcept
{
    if(push_first(node))
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
    listSize++;
}

template<typename T>
void List<T>::pop_back()
{
    if (tail != nullptr)
    {
        tail = tail->prev.lock();
        tail->next.reset();
    }
}

template<typename T>
void List<T>::pop_front()
{
    if (head != nullptr)
    {
        head = head->next.lock();
        head->prev.reset();
    }
}

template<typename T>
void List<T>::show() const noexcept
{
    if ( head == nullptr ) cout << "List is empty!" << endl;
    else 
    {
        shared_ptr<Node<T>> node = head;
        cout << " List: " << endl;
        int i = 1;
        while(node != nullptr)
        {
            cout << "Nr " << i << ": " << node->value << endl;
            i++;
            node = node->next.lock();
        }
        cout << endl;
    }
}

