#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PhysicsBody.h"
#include "PhysicsLayer.h"

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
		long unsigned deltaAccumulator = 0;
		list<PhysicsLayer> layers;
	public:
		World(Vector2f gravity);

		void AddPhysicsBody(PhysicsBody& obj);
		void RemovePhysicsBody(PhysicsBody& obj);
		void UpdatePhysics(unsigned long deltaMilliseconds, unsigned long msPerTick = 0);
		void VisualizeAllBounds(RenderWindow& window);
		void setIgnoreMovement(bool ignore = true);
		/// <summary>
		/// Prevents a layer from interacting with another layer.
		/// </summary>
		/// <param name="layer1">The first layer to compare</param>
		/// <param name="layer2">The second layer to compare</param>
		void ExcludeCollision(unsigned int layer1, unsigned int layer2);
		/// <summary>
		/// Allows a layer to interact with another layer. Note that layers can interact with other layers by default.
		/// </summary>
		/// <param name="layer1">The first layer to compare</param>
		/// <param name="layer2">The second layer to compare</param>
		void IncludeCollision(unsigned int layer1, unsigned int layer2);
		/// <summary>
		/// Check if a layer is allowed to collide with another layer.
		/// </summary>
		/// <param name="layer1">The first layer to compare</param>
		/// <param name="layer2">The second layer to compare</param>
		/// <returns></returns>
		bool HasCollision(unsigned int layer1, unsigned int layer2);
	};
}


