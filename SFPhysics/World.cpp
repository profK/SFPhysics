#include "pch.h"
#include "World.h"


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
