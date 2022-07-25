#pragma once
#include <list>
#include <iterator>

using namespace std;

template<class PhysicsShapeClass>
class PhysicsShapeList
{

	using ListType = list<PhysicsShapeClass*>;
	using ListIter = std::_List_iterator<std::_List_val<std::_List_simple_types<PhysicsShapeClass*>>>;

	
private:
	ListType list;
	ListType removalList;
public:

	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = PhysicsShapeClass;
	using pointer = PhysicsShapeClass*;  // or also value_type*
	using reference = PhysicsShapeClass&;  // or also value_type&

	struct iterator   {
		ListIter lIter;
		iterator(ListIter iter) { lIter = iter; }

		reference operator*() const { return **lIter; }
		pointer operator->() { return lIter.operator->(); }

		// Prefix increment
		iterator& operator++() {lIter++; return *this; }

		// Postfix increment
		iterator operator++(int) { iterator tmp = *this; ++lIter; return tmp; }

		friend bool operator== (const iterator& a, const iterator& b) { return a.lIter == b.lIter; };
		friend bool operator!= (const iterator& a, const iterator& b) { return a.lIter != b.lIter; };

		
	};

	PhysicsShapeClass& Create() {
		PhysicsShapeClass* ptr = new PhysicsShapeClass();
		list.push_back(ptr);
		return *ptr;
	};
	void QueueRemove(PhysicsShapeClass& element) {
		removalList.push_back(&element);
	}

	void Remove(PhysicsShapeClass& element) {
		QueueRemove(element);
	}

	void DoRemovals() {
		for (auto element : removalList) {
			list.remove(element);
			delete element;
		}
		removalList.clear();
	}
	
	iterator begin()  {
		return iterator(list.begin());
	}
	iterator end()  {
		return iterator(list.end());
	}
};

