#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../SFPhysics/CircleBounds.h"
#include "../SFPhysics/AABB.h"
#include <SFML/Window.hpp>
#include "../SFPhysics/DynamicPhysicsObject.h"
#include "../SFPhysics/World.h"
#include <ctime> 
#include <chrono>
#include "../SFPhysics/StaticPhysicsObject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace sfp;
using namespace std::chrono;

namespace MSTests
{
	TEST_CLASS(Intersectiontests)
	{
	public:
		
		TEST_METHOD(CircleVCircle)
		{
			CircleBounds c1(Vector2f(10, 10), 5);
			CircleBounds c2(Vector2f(100, 100), 10);
			CircleBounds c3(Vector2f(15, 10), 5);
			BoundsCollisionResult result1 = c1.collideWith(c2);
			Assert::IsFalse(result1.hasCollided);
			BoundsCollisionResult result2 = c1.collideWith(c3);
			Assert::IsTrue(result2.hasCollided);
			Assert::AreEqual(5.0f, result2.penetration, L"Penetration not eq 5");
			CircleBounds c4(Vector2f(17.25, 10), 5);
			BoundsCollisionResult result3 = c1.collideWith(c4);
			Assert::IsTrue(result3.hasCollided);
			Assert::AreEqual(2.75f, result3.penetration, L"Penetration not eq 2.75");
			Assert::AreEqual(-1.0f, result3.normal.x, L"normal X not -1");
			Assert::AreEqual(0.0f, result3.normal.y, L"normal X not 0");
		};

		TEST_METHOD(BoxVBox)
		{
			AABB b1(Vector2f(0, 0), Vector2f(10, 10));
			AABB b2(Vector2f(100, 100), Vector2f(110, 110));
			BoundsCollisionResult result = b1.collideWith(b2);
			Assert::IsFalse(result.hasCollided);
			AABB b3(Vector2f(5, 0), Vector2f(15, 10));;
			BoundsCollisionResult result2 = b1.collideWith(b3);
			Assert::IsTrue(result2.hasCollided);
			Assert::AreEqual(5.0f, result2.penetration, L"Penetration not eq 10");
			Assert::AreEqual(0.0f, result2.normal.y, L"normal Y not 1");
			Assert::AreEqual(1.0f, result2.normal.x, L"normal X not 0");
		}

		TEST_METHOD(BoxVCircle)
		{
			CircleBounds c1(Vector2f(12.5, 5), 5);
			AABB b1(Vector2f(0, 0), Vector2f(10, 10));
			AABB b2(Vector2f(20, 20), Vector2f(30, 30));
			BoundsCollisionResult result = b2.collideWith(c1);
			Assert::IsFalse(result.hasCollided);
			BoundsCollisionResult result2 = b1.collideWith(c1);
			Assert::IsTrue(result2.hasCollided);
			Assert::AreEqual(2.5f, result2.penetration, L"c1Penetration not eq 2.5");
			Assert::AreEqual(0.0f, result2.normal.y, L"normal Y not 0");
			Assert::AreEqual(1.0f, result2.normal.x, L"normal X not -1");
			
		}

		
		TEST_METHOD(VisualTest)
		{
			World world(Vector2f(0, 1));
			world.AddPhysicsObject(
				DynamicPhysicsObject(CircleBounds(Vector2f(100, 100), 50)));
			world.AddPhysicsObject(
				DynamicPhysicsObject(AABB(Vector2f(0, 0), Vector2f(40, 120)),
					0.75f)
			);
			//world.AddPhysicsObject(
			//	DynamicPhysicsObject(AABB(Vector2f(20, 20), Vector2f(40, 40))));
			world.AddPhysicsObject(
				StaticPhysicsObject(AABB(Vector2f(0, 550), Vector2f(800, 600)))
			);
			RenderWindow window(VideoMode(800, 600), "Test Window");
			system_clock::time_point last = system_clock::now();
			while (!Keyboard::isKeyPressed(Keyboard::Space)) {
				window.clear(Color::Black);
				system_clock::time_point current = system_clock::now();
				unsigned int deltaMs =
					std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count();
				world.UpdatePhysics(deltaMs);
				last = current;
				world.VisualizeAllBounds(window);
				Font fnt;
				Assert::IsTrue(fnt.loadFromFile("arial.ttf"));
				Text text("Push space to continue...", fnt);
				text.setPosition(0, 500);
				window.draw(text);
				window.display();          
			}
		}
			
	};
}
