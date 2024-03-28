#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../SFPhysics/include/SFPhysics.h"
#include <ctime> 
#include <chrono>



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
			AABB b3(Vector2f(5, 0), Vector2f(15, 10));
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

		TEST_METHOD(BounceTest) 
		{
			RenderWindow window(VideoMode(800, 600), "Bounce");
			World world(Vector2f(0, 1));
			PhysicsCircle ball;
			ball.setCenter(Vector2f(400, 300));
			ball.setRadius(20);
			world.AddPhysicsBody(ball);

			PhysicsRectangle floor;
			floor.setSize(Vector2f(800, 20));
			floor.setCenter(Vector2f(400, 590));
			floor.setStatic(true);
			world.AddPhysicsBody(floor);

			Clock clock;
			Time lastTime(clock.getElapsedTime());
			Time runTime = clock.getElapsedTime() + sf::seconds(5);
			while (clock.getElapsedTime()<runTime) {
				// calculate MS since last frame
				Time currentTime(clock.getElapsedTime());
				Time deltaTime(currentTime - lastTime);
				int deltaTimeMS(deltaTime.asMilliseconds());
				if (deltaTimeMS > 0) {
					world.UpdatePhysics(deltaTimeMS);
					lastTime = currentTime;
				}
				window.clear(Color(0, 0, 0));
				window.draw(ball);
				window.draw(floor);
				window.display();
			}
		}

		TEST_METHOD(SubdevidedBounceTest)
		{
			RenderWindow window(VideoMode(800, 600), "Bounce with 1ms phsyics tick");
			World world(Vector2f(0, 1));
			PhysicsCircle ball;
			ball.setCenter(Vector2f(400, 300));
			ball.setRadius(20);
			world.AddPhysicsBody(ball);

			PhysicsRectangle floor;
			floor.setSize(Vector2f(800, 20));
			floor.setCenter(Vector2f(400, 590));
			floor.setStatic(true);
			world.AddPhysicsBody(floor);

			Clock clock;
			Time lastTime(clock.getElapsedTime());
			Time runTime = clock.getElapsedTime() + sf::seconds(5);
			while (clock.getElapsedTime() < runTime) {
				// calculate MS since last frame
				Time currentTime(clock.getElapsedTime());
				Time deltaTime(currentTime - lastTime);
				int deltaTimeMS(deltaTime.asMilliseconds());
				if (deltaTimeMS > 0) {
					world.UpdatePhysics(deltaTimeMS);
					lastTime = currentTime;
				}
				window.clear(Color(0, 0, 0));
				window.draw(ball);
				window.draw(floor);
				window.display();
			}
		}

		TEST_METHOD(ListTest)
		{
			PhysicsShapeList<PhysicsCircle> circles;
			World world(Vector2f(0, 1));
			for (int i(0); i < 4; i++) {
				PhysicsCircle& c = circles.Create();
				c.setSize(Vector2f(30, 30));
				c.setCenter(Vector2f(rand() % 600 + 100, rand() % 400));
				world.AddPhysicsBody(c);
			}
			
			RenderWindow window(VideoMode(800, 600), "Test Window");
			system_clock::time_point last = system_clock::now();
			while (!Keyboard::isKeyPressed(Keyboard::Space)){	
				system_clock::time_point current = system_clock::now();
				unsigned int deltaMs =
					std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count();
				if (deltaMs == 0) {
					continue;
				}
				window.clear(Color::Black);
				world.UpdatePhysics(deltaMs);
				last = current;
				//world.VisualizeAllBounds(window);
				Font fnt;
				Assert::IsTrue(fnt.loadFromFile("../../arial.ttf"));
				Text text("Push space to continue...", fnt);
				text.setPosition(0, 500);
				for (auto circle : circles)
					window.draw(circle);
				window.display();
			}

		}


		TEST_METHOD(VisualTest)
		{
			World world(Vector2f(0, 1));
			
			PhysicsBodyT<CircleBounds> b1;
			b1.getBounds().setSize(Vector2f(10, 10));
			world.AddPhysicsBody(b1);
			PhysicsBodyT<AABB> pb2;
			pb2.getBounds().setSize(Vector2f(10, 10));
			pb2.setPosition(Vector2f(400, 200));
			world.AddPhysicsBody(pb2);
			PhysicsBodyT<AABB> pb3;
			pb3.getBounds().setSize(Vector2f(800, 20));
			pb3.setPosition(Vector2f(400, 590));
			pb3.setStatic(true);
			world.AddPhysicsBody(pb3);
			RenderWindow window(VideoMode(800, 600), "Test Window");
			system_clock::time_point last = system_clock::now();
			while (!Keyboard::isKeyPressed(Keyboard::Space)) {
				window.clear(Color::Black);
				system_clock::time_point current = system_clock::now();
				unsigned int deltaMs =
					std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count();
				if (deltaMs == 0) {
					continue;
				}
				world.UpdatePhysics(deltaMs);
				last = current;
				world.VisualizeAllBounds(window);
				Font fnt;
				//Assert::IsTrue(fnt.loadFromFile("arial.ttf"));
				//Text text("Push space to continue...", fnt);
				//text.setPosition(0, 500);
				//window.draw(text);
				window.display();
			}
			
		}

		TEST_METHOD(SetVelocityTest) {
			RenderWindow window(VideoMode(800, 600), "Set velocity test");
			World world(Vector2f(0, 0));
			PhysicsCircle circle;
			circle.setCenter(Vector2f(100, 100));
			circle.setSize(Vector2f(50, 50));
			circle.setVelocity(Vector2f(0, -1));
			world.AddPhysicsBody(circle);
			system_clock::time_point last = system_clock::now();
			while (!Keyboard::isKeyPressed(Keyboard::Space)) {
				window.clear(Color::Black);
				system_clock::time_point current = system_clock::now();
				unsigned int deltaMs =
					std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count();
				if (deltaMs == 0) {
					continue;
				}
				world.UpdatePhysics(deltaMs);
				last = current;
				world.VisualizeAllBounds(window);
				//Font fnt;
				//Assert::IsTrue(fnt.loadFromFile("../../arial.ttf"));
				//Text text("Push space to continue...", fnt);
				//text.setPosition(0, 500);
				window.draw(circle);
				window.display();
			}
		}

		TEST_METHOD(SpriteResizeTest)
		{

			const int WINDOW_WIDTH = 800;
			const int WINDOW_HEIGHT = 600;
			RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sprite Resize Bounce");
			World world(Vector2f(0, 1));

			Texture texture;
			Assert::IsTrue(texture.loadFromFile("../../smiley.png"));

			auto createShape = [&world, &texture](PhysicsSprite& sprite, float size, Vector2f center)
				{
					sprite.setTexture(texture);
					sprite.setSize({ size, size });
					sprite.setCenter(center);
					world.AddPhysicsBody(sprite);
				};


			PhysicsShapeList<PhysicsSprite> list;
			const int COUNT = 3;
			float spacing = WINDOW_WIDTH / COUNT;
			float half_space = spacing / 2.0f;
			for (int i = 0; i < COUNT; i++)
			{
				PhysicsSprite& sprite = list.Create();
				float x = spacing * i + half_space;
				createShape(sprite, (i + 1) * 50, {x, WINDOW_HEIGHT / 2.0f});
			}

			PhysicsRectangle floor;
			floor.setSize(Vector2f(800, 20));
			floor.setCenter(Vector2f(400, 590));
			floor.setStatic(true);
			world.AddPhysicsBody(floor);

			Clock clock;
			Time lastTime(clock.getElapsedTime());
			Time runTime = clock.getElapsedTime() + sf::seconds(10);
			while (clock.getElapsedTime() < runTime) {

				// calculate MS since last frame
				Time currentTime(clock.getElapsedTime());
				Time deltaTime(currentTime - lastTime);
				int deltaTimeMS(deltaTime.asMilliseconds());
				if (deltaTimeMS > 0) {
					world.UpdatePhysics(deltaTimeMS);
					lastTime = currentTime;
				}
				window.clear(Color(0, 0, 0));

				for (auto sprite : list)
				{
					window.draw(sprite);
				}
				window.draw(floor);
				world.VisualizeAllBounds(window);
				window.display();

				Event ev;
				if (window.pollEvent(ev))
				{
					if (ev.key.code == Keyboard::Space)
					{
						break;
					}
				}
			}
		}

		TEST_METHOD(SFMLBinding)
		{
			World world(Vector2f(0, 1));
			PhysicsCircle circle;
			circle.setCenter(Vector2f(100, 100));
			circle.setSize(Vector2f(50, 50));
			world.AddPhysicsBody(circle);
			PhysicsRectangle fallingRect;
			fallingRect.setCenter(Vector2f(20, 60));
			fallingRect.setSize(Vector2f(40, 120));
			world.AddPhysicsBody(fallingRect);
			PhysicsRectangle floor;
			floor.setCenter(Vector2f(400, 575));
			floor.setSize(Vector2f(800, 50));
			floor.setStatic(true);
			world.AddPhysicsBody(floor);
			Texture landerTex;
			Assert::IsTrue(landerTex.loadFromFile("../../smiley.png"));
			PhysicsSprite lander;
			lander.setCenter(Vector2f(600, 20));
			world.AddPhysicsBody(lander);
			lander.setTexture(landerTex);
			PhysicsConvexPolygon ship;
			ship.setPointCount(3);
			ship.setPoint(0, Vector2f(-25, 25));
			ship.setPoint(1, Vector2f(0, -30));
			ship.setPoint(2, Vector2f(25, 25));
			ship.setCenter(Vector2f(400, 50));
			world.AddPhysicsBody(ship);
			RenderWindow window(VideoMode(800, 600), "Test Window");
			system_clock::time_point last = system_clock::now();
			while (!Keyboard::isKeyPressed(Keyboard::Space)) {
				window.clear(Color::Black);
				system_clock::time_point current = system_clock::now();
				unsigned int deltaMs =
					std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count();
				if (deltaMs == 0) {
					continue;
				}
				world.UpdatePhysics(deltaMs);
				last = current;
				world.VisualizeAllBounds(window);
				//Font fnt;
				//Assert::IsTrue(fnt.loadFromFile("../../arial.ttf"));
				//Text text("Push space to continue...", fnt);
				//text.setPosition(0, 500);
				window.draw(circle);
				window.draw(fallingRect);
				window.draw(floor);
				//window.draw(text);
				window.draw(lander);
				window.draw(ship);
				window.display();
			}
		}
	};

}
