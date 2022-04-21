#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"


using namespace sf;

namespace sfp {
	struct PhysicsBodyCollisionResult;
	class PhysicsBody
	{
	protected:
		Bounds* bounds; // has to be a pointer for late-set
		float restitution;
		float mass;
		bool isStatic;
		Vector2f velocity;
	public:
		PhysicsBody();
		PhysicsBody(Bounds& bounds, bool isStatic = false,
			float restitution=1.0f,float mass=1.0f);
		void applyImpulse(Vector2f impulse);
		void update(unsigned int deltaMillisconds);
		void setPosition(Vector2f center);
		Vector2f getPosition();
		Bounds& getBounds();
		void setBounds(Bounds& bounds);
		void visualizeBounds(RenderWindow& window);
		Vector2f getVelocity();
		virtual void setVelocity(Vector2f v);
		float getRestitution();
		virtual float getMass();
		PhysicsBodyCollisionResult collideWith(PhysicsBody& other);
		virtual void collisionCallback(PhysicsBodyCollisionResult& collision);
	};
}

