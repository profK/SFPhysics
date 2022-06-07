#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PhysicsBody.h"

using namespace sf;
using namespace std;

namespace sfp {
	class World
	{
	private:
		Vector2f gravity;
		list<PhysicsBody*> objects; // becomes ptrs internally but never exposed
		bool ignoreMovement;
		list<PhysicsBody*> removalList;
	public:
		World(Vector2f gravity);

		void AddPhysicsBody(PhysicsBody& obj);
		void RemovePhysicsBody(PhysicsBody& obj);
		void UpdatePhysics(unsigned long deltaMilliseconds);
		void VisualizeAllBounds(RenderWindow& window);
		void setIgnoreMovement(bool ignore = true);
	};
}


