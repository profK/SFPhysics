
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
        PhysicsCircle(Vector2f position, float radius, bool isStatic = false);
    };
}

