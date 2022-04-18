#include "pch.h"
#include "../SFPhysics/CircleBounds.h"

using namespace sfp;

TEST(IntersectionTests, CircleVCircle) {
	CircleBounds c1(Vector2f(10, 10), 5);
	CircleBounds c2(Vector2f(100, 100), 10);
	CircleBounds c3(Vector2f(15, 10), 5);
	BoundsCollisionResult result1 = c1.collideWith(c2);
	EXPECT_FALSE(result1.hasCollided);
	BoundsCollisionResult result2 = c1.collideWith(c3);
	EXPECT_TRUE(result2.hasCollided);
	EXPECT_EQ(result2.penetration, 5);
	
}