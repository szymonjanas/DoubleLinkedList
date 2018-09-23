#include "listService.hpp"
#include <exception>
#include "main_exceptions.hpp"



template<typename TT>
shared_ptr<listNode<TT>> List<TT>::getHead() const
{
    return head;
}

template<typename TT>
shared_ptr<listNode<TT>> List<TT>::getTail() const
{
    return this->tail;
}

template<typename TT>
unsigned int List<TT>::getListSize() const
{
    return listSize;
}

template<typename TT>
shared_ptr<listNode<TT>> List<TT>::getNode(unsigned int position) const
{
    try
    {
        shared_ptr<listNode<TT>> newNode = head;
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



