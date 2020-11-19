#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"
#include "base.hpp"

class bubble_sort : public Sort{
        public:
        /* Constructors */
        bubble_sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container);
};

#endif