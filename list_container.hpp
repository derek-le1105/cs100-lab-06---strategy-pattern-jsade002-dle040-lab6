#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "container.hpp"
#include "sort.hpp"
#include "base.hpp"
#include <iostream>
#include <list>

class Sort;
class Base;

class listContainer : public Container{
    protected:
        std::list<Base*> container;
        Sort* sort_function;
    public:
        listContainer(): sort_function(nullptr) {};
        listContainer(Sort* function): sort_function(function) {};

        void set_sort_function(Sort* sort_function);

        virtual void add_element(Base* element) = 0;
        // iterate through trees and output the expressions (use stringify())
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm. Checks if sort_function is not
        // null, throw exception if otherwise
        virtual void sort() = 0;

        /* Functions Needed to Sort */
        //switch tree locations
        virtual void swap(int i, int j) = 0;
        // get top ptr of tree at index i
        virtual Base* at(int i) = 0;
        // return container size
        virtual int size() = 0;
};


#endif //__LIST_CONTAINER_HPP__