#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PhysicsObject.h"

using namespace sf;
using namespace std;

namespace sfp {
	class World
	{
	private:
		Vector2f gravity;
		list<PhysicsObject *> objects; // becomes ptrs internally but never exposed
	public:
		World(Vector2f gravity);
		void AddPhysicsObject(PhysicsObject &obj);
		void RemovePhysicsObject(PhysicsObject& obj);
	};
}


