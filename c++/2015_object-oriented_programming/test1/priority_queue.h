#pragma once
#include <vector>
#include <iostream>
using std::vector;


//! Dumb vector-based implementation priority queue
template <typename T>
class PriorityQueue
{
public:
    //! Delete queue;
    ~PriorityQueue();
    //! Add a new element to the queue with the given value and priority
    void enqueue(const T &value, int priority);
    //! Delete and return the element with the highest priority
    /*! Returns random value if is empty **/
    T dequeue();
private:
    class Element
    {
    public:
        T value;
        int priority;
        Element(T value, int priority) : value(value), priority(priority) {}
    };
    vector<Element*> data;
};


template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    for (auto element: data)
        delete element;
}


template <typename T>
void PriorityQueue<T>::enqueue(const T &value, int priority)
{
    int i = 0;
    while ((unsigned int)i < data.size() && data[i]->priority < priority)
        i++;
    typename vector<Element*>::iterator it = data.begin();
    data.insert(it + i, new Element(value, priority));
}


template <typename T>
T PriorityQueue<T>::dequeue()
{
    if (data.size() == 0)
    {
        //pseudo-exception
        std::cout << "Error: empty queue. ";
        //no return, complilator warning, Timofey approved
    }
    else
    {
        auto result = data.back()->value;
        delete data.back();
        data.pop_back();
        return result;
    }
}
