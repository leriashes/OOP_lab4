#pragma once
template <class T>
class MyElement
{
private:
    T object;
    MyElement* next_node;
public:
    MyElement(T const& t) { object = t; next_node = 0; }
    ~MyElement() { if (next_node) delete next_node; }
    MyElement* next() { return next_node; }
    T* get() { return &object; }
    void push(T const& t) 
    {
        cout << "MyElement push: " << t << endl;
        if (next_node) next_node->push(t);
        else next_node = new MyElement(t);
    }
};
