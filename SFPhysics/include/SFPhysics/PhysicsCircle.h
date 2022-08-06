#include "CenteredCircle.h"
#include "CircleBounds.h"
#include "PhysicsShapeT.h"


using namespace sf;

namespace sfp {
    class PhysicsCircle : public PhysicsShapeT<CenteredCircle,CircleBounds>
    {
    
    };
}

