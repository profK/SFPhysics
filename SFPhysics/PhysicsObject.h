#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include "PhysicsObjectCollisionResult.h"

using namespace sf;

namespace sfp {
	class PhysicsObject
	{
	protected:
		Bounds* bounds; // has to be a pointer for late-set
		float restitution;
		float mass;
	public:
		PhysicsObject();
		PhysicsObject(Bounds& bounds,float restitution=1.0f,float mass=1.0f);
		virtual void applyImpulse(Vector2f impulse)=0;
		virtual void update(unsigned int deltaMillisconds)=0;
		void setPosition(Vector2f center);
		Vector2f getPosition();
		Bounds& getBounds();
		void setBounds(Bounds& bounds);
		void visualizeBounds(RenderWindow& window);
		virtual Vector2f getVelocity() = 0;
		virtual void setVelocity(Vector2f v) = 0;
		float getRestitution();
		virtual float getMass();
		PhysicsObjectCollisionResult collideWith(PhysicsObject& other);

	};
}


