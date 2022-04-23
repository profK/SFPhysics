
#include "CircleBounds.h"
#include "PhysicsBody.h"
#include "CenteredCircle.h"

using namespace sf;

namespace sfp {
    class PhysicsCircle :
        public CenteredCircle, public PhysicsBody
    {
    private:
        CircleBounds defaultBounds;
    public:
        PhysicsCircle(Vector2f position=Vector2f(25,25), float radius=50, bool isStatic = false);
        void setCenter(Vector2f center);
        void setRadius(float radius);
        void setPosition(Vector2f position);
    };
}

