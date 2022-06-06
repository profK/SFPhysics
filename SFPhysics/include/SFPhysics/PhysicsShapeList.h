#pragma once
#include <list>
#include <iterator>

using namespace std;

template<class PhysicsShapeClass>
class PhysicsShapeList
{

	using ListType = list<PhysicsShapeClass*>;
	
private:
	ListType list;
public:
	typedef typename ListType::iterator iterator;

	PhysicsShapeClass& Create() {
		PhysicsShapeClass* ptr = new PhysicsShapeClass();
		list.push_back(ptr);
		return *ptr;
	};
	void Remove(PhysicsShapeClass& element) {
		list.remove(&element);
		delete &element;
	}
	
	iterator begin()  {
		return list.begin();
	}
	iterator end()  {
		return list.end();
	}
};

