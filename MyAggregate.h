#pragma once
#include "MyElement.h"
#include "MyIterator.h"

template <class T>
class MyAggregate
{
public:
    typedef MyElement<T> node;
    typedef MyIterator <node, T> myIter;
private:
    node* root;
public:
    MyAggregate() { root = 0; }
    ~MyAggregate() { if (root) delete root; }
    myIter begin() { return myIter(root); }
    myIter end() { return  myIter(0); }
    void push(T const& t) {
        if (root) root->push(t);
        else  root = new node(t);
    }
};
