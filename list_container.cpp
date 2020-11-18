#include "list_container.hpp"

void listContainer::set_sort_function(Sort* sort_function){
    this->sort_function = sort_function;
}

void listContainer::add_element(Base* element){
    container.push_back(element);
}

void listContainer::print(){
    std::list<Base*> tempList = container;
    int count = container.size();

    while(!tempList.empty()){
        std::cout << tempList.front()->stringify();
        tempList.pop_front();
    }
}

void listContainer::sort(){
    sort_function->sort(this);
}

void listContainer::swap(int i , int j){
    Base* jBase;
    Base* iBase;
    
    std::list<Base*> tempList;
    std::list<Base*> tempList2 = container;
    std::list<Base*> tempList3 = container;
    int count = 0;
    while(!tempList2.empty()){
        if(count == j)
            jBase = this->at(j);
        else if(count == i)
            iBase = this->at(i);
        else{
            tempList2.pop_front();
            count++;
        }
    }
    count = 0;
    while(!tempList3.empty()){
         if(count == j)
            tempList.push_back(jBase);
        else if(count == i)
            tempList.push_back(iBase);
        else{
            tempList2.push_back(tempList3.front());
            tempList3.pop_front();
            count++;
        }
    }

    container = tempList;
}

Base* listContainer::at(int i){
    std::list<Base*> tempList = container;
    int count = 0;
    while(count != i){
        tempList.pop_front();
        ++count;
    }

    return tempList.front();
}

int listContainer::size(){
    return container.size();
}