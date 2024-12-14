#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"


using namespace sf;

namespace sfp {
	struct PhysicsBodyCollisionResult;
	class PhysicsBody 
	{
	protected:
		
		float restitution;
		float mass;
		bool isStatic;
		Vector2f velocity;
		bool moved;
		unsigned int layer;
	public:
		PhysicsBody();
		PhysicsBody(Bounds& bounds, bool isStatic = false,
			float restitution=1.0f,float mass=1.0f, int layer = 0);
		void applyImpulse(Vector2f impulse);
		void update(unsigned int deltaMillisconds);
		void setPosition(Vector2f center);
		Vector2f getPosition();
		virtual Bounds& getBounds()=0;
		void setBounds(Bounds& bounds);
		void visualizeBounds(RenderWindow& window);
		Vector2f getVelocity();
		virtual void setVelocity(Vector2f v);
		float getRestitution();
		void setRestitution(float r);
		virtual float getMass();
		virtual void setMass(float m);
		bool getStatic();
		void setStatic(bool s);
		PhysicsBodyCollisionResult collideWith(PhysicsBody& other);
		void setMoved(bool moved = false);
		bool hasMoved();
		/// <summary>
		/// Sets the collision layer to be set to this object. Default is 0.
		/// </summary>
		/// <param name="layer">The layer to use.</param>
		void setLayer(unsigned int layer);
		/// <summary>
		/// Gets the current layer associated with this object. Default is 0.
		/// </summary>
		/// <returns>The layer this object is associated with.</returns>
		unsigned int getLayer();

		bool operator == (const PhysicsBody& other) {
			return this == &other;
		}

		bool operator != (const PhysicsBody& other) {
			return !(this->operator==(other));
		}
		
		function<void(PhysicsBodyCollisionResult&)> onCollision = [this](PhysicsBodyCollisionResult& other) {
			//nop
		};
		function<void(float deltaMS)> onUpdate = [this](float deltaMS) {
			//nop
		};
	};
}


