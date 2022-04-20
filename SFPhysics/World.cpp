#include "pch.h"
#include "World.h"
#include "PhysicsObjectCollisionResult.h"

//internal utility functions
namespace sfp {
	static float Dot(Vector2f a, Vector2f b){
		return (a.x * b.x) + (a.y * b.y);
	}
	static void ResolveCollision(PhysicsObjectCollisionResult &collision)
	{
		PhysicsObject &A = collision.object1;
		PhysicsObject &B = collision.object2;
		// Calculate relative velocity
		Vector2f rv = B.getVelocity() - A.getVelocity();

		// Calculate relative velocity in terms of the normal direction
		float velAlongNormal = Dot(rv, collision.normal);

		// Do not resolve if velocities are separating
		if (velAlongNormal > 0)
			return;

		// Calculate restitution
		float e = min(A.getRestitution(), B.getRestitution());

		// Calculate impulse scalar
		float j = -(1 + e) * velAlongNormal;
		j /= 1 / A.getMass() + 1 / B.getMass();

		
		// Apply impulse
		Vector2f impulse = j * collision.normal;
		float aMass = A.getMass();
		float bMass = B.getMass();
		if (aMass != 0) {
			A.setVelocity(A.getVelocity() - 1 / aMass * impulse);
		}
		if (bMass != 0) {
			B.setVelocity(B.getVelocity() + 1 / bMass * impulse);
		}
		
	}
}


// class functions
sfp::World::World(Vector2f gravity):
	gravity(gravity)
{

}

void sfp::World::AddPhysicsObject(PhysicsObject& obj)
{
	objects.push_back(&obj);
}

void sfp::World::RemovePhysicsObject(PhysicsObject& obj)
{
	objects.remove(&obj);
}

void sfp::World::UpdatePhysics(unsigned long deltaMilliseconds)
{
	for (auto obj : objects) {
		obj->applyImpulse(gravity * (float)deltaMilliseconds/1000.0f);
		// do collision, very stupid right now. long run should not check 
		// objecst that havent moved
		for (auto obj2 : objects) {
			if (obj != obj2) {
				PhysicsObjectCollisionResult collision =
					obj->collideWith(*obj2);
				if (collision.hasCollided) {
					ResolveCollision(collision);
				}
			}
		}
		obj->update(deltaMilliseconds);
	}
}

void sfp::World::VisualizeAllBounds(RenderWindow& window)
{
	for (auto obj : objects) {
		obj->visualizeBounds(window);
	}
}
