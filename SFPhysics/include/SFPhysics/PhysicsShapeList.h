#pragma once
#include <list>
#include <iterator>
#include "PhysicsShape.h"

using namespace std;
namespace sfp {

    template<class T>
    class PhysicsShapeList
    {

        using ListType = list<T*>;
        using ListIter = std::_List_iterator<std::_List_val<std::_List_simple_types<T*>>>;


    private:
        ListType list;
        ListType removalList;
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T*;
        using pointer = T**;  // or also value_type*
        using reference = T&;  // or also value_type&

        struct iterator {
            ListIter lIter;
            iterator(ListIter iter) { lIter = iter; }

            reference operator*() const { return **lIter; }
            pointer operator->() { return lIter.operator->(); }

            // Prefix increment
            iterator& operator++() { lIter++; return *this; }

            // Postfix increment
            iterator operator++(int) { iterator tmp = *this; ++lIter; return tmp; }

            friend bool operator== (const iterator& a, const iterator& b) { return a.lIter == b.lIter; };
            friend bool operator!= (const iterator& a, const iterator& b) { return a.lIter != b.lIter; };


        };


        T& Create() {
            T* ptr = new T();
            list.push_back(ptr);
            return (T&)*ptr;
        };
        void QueueRemove(T& element) {
            removalList.push_back(&element);
        }

        void Remove(T& element) {
            QueueRemove(element);
        }

        void DoRemovals() {
            for (auto element : removalList) {
                list.remove(element);
                delete element;
            }
            removalList.clear();
        }

        iterator begin() {
            return iterator(list.begin());
        }
        iterator end() {
            return iterator(list.end());
        }


    };
}




