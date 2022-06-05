#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PhysicsShape.h"

using namespace sf;
using namespace std;

namespace sfp {
	class World
	{
	private:
		Vector2f gravity;
		bool ignoreMovement;
		vector<reference_wrapper<PhysicsShape>> objects;
	public:
		
		World(Vector2f gravity);
		void AddPhysicsShape(PhysicsShape& shape);
		vector<reference_wrapper<PhysicsShape>> getShapeRefs();
		void UpdatePhysics(unsigned long deltaMilliseconds);
		void VisualizeAllBounds(RenderWindow& window);
		void setIgnoreMovement(bool ignore = true);
	};
}


