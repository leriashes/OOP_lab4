#pragma once
template <class node, class T>
class MyIterator
{
private:
    node* node_ptr;

public:
    MyIterator(node* n) { node_ptr = n; }
    T* next() { return node_ptr->get(); }
    void  operator ++ () { node_ptr = node_ptr->next(); }
    MyIterator operator ++ (int) {
        MyIterator iter(*this);        ++(*this);
        return iter;
    }
    bool operator == (MyIterator const& i) {
        return node_ptr == i.node_ptr;
    }
    bool operator != (MyIterator const& i) { return !(*this == i); }
};