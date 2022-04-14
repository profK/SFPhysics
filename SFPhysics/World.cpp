#include "pch.h"
#include "World.h"


sfp::World::World(Vector2f gravity):
	gravity(gravity)
{

}

void sfp::World::AddPhysicsObject(Bounds& obj)
{
	objects.push_back(&obj);
}

void sfp::World::RemovePhysicsObject(Bounds& obj)
{
	objects.remove(&obj);
}
