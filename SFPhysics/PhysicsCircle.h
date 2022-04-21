
#include "CircleBounds.h"
#include "PhysicsBody.h"
#include "CenteredCircle.h"

using namespace sf;

namespace sfp {
    class PhysicsCircle :
        public CenteredCircle,public CircleBounds, public PhysicsBody
    {
    public:
        PhysicsCircle(Vector2f position, float radius, bool isStatic = false);
    };
}

