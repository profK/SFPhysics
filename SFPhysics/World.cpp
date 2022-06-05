#include "pch.h"
#include "World.h"
#include "PhysicsBodyCollisionResult.h"

//internal utility functions
namespace sfp {
	static float Dot(Vector2f a, Vector2f b){
		return (a.x * b.x) + (a.y * b.y);
	}
	static void ResolveCollision(PhysicsBodyCollisionResult &collision)
	{
		PhysicsBody &A = collision.object1;
		PhysicsBody &B = collision.object2;
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

void sfp::World::AddPhysicsShape(PhysicsShape& shape)
{
	PhysicsShape& clone = shape.clone();
	objects.push_back(clone);
}

vector<reference_wrapper<sfp::PhysicsShape>> sfp::World::getShapeRefs()
{
	return objects;
}



void sfp::World::UpdatePhysics(unsigned long deltaMilliseconds)
{
	for (auto ref : objects) {
		PhysicsShape& obj = ref.get();
		obj.getBody().applyImpulse(gravity * (float)deltaMilliseconds/1000.0f);
		// do collision, very stupid right now. long run should not check 
		// objecst that havent moved
		for (auto ref2 : objects) {
			PhysicsShape& obj2 = ref.get();
			if ((&obj != &obj2)&&(ignoreMovement||obj.getBody().hasMoved()||obj2.getBody().hasMoved())) {
				PhysicsBodyCollisionResult collision =
					obj.getBody().collideWith(obj2.getBody());
				if (collision.hasCollided) {
					if (collision.object1.onCollision) {
						collision.object1.onCollision(collision);
					}
					ResolveCollision(collision);
				}
			}
		}
		obj.getBody().update(deltaMilliseconds);
		Vector2f pos = obj.getBody().getPosition();
		CenteredShape& shape = obj.getShape();
		shape.setCenter(pos); 
	}
}

void sfp::World::VisualizeAllBounds(RenderWindow& window)
{
	for (auto ref : objects) {
		PhysicsShape& obj = ref.get();
		obj.getBody().visualizeBounds(window);
	}
}

void sfp::World::setIgnoreMovement(bool  ignore)
{
	ignoreMovement = ignore;
}
