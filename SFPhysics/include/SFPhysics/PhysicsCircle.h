#include "CenteredCircle.h"
#include "CircleBounds.h"
#include "PhysicsShape.h"


using namespace sf;

namespace sfp {
    class PhysicsCircle : public PhysicsShape<CenteredCircle, CircleBounds>
    {
    public:
        PhysicsCircle();
    };
}

