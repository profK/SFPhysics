#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Bounds.h"

using namespace sf;
using namespace std;

namespace sfp {
	class World
	{
	private:
		Vector2f gravity;
		list<Bounds*> objects; // becomes ptrs internally but never exposed
	public:
		World(Vector2f gravity);
		void AddPhysicsObject(Bounds&obj);
		void RemovePhysicsObject(Bounds& obj);
	};
}


