#include "CenteredCircle.h"
#include "CircleBounds.h"
#include "PhysicsShapeGlue.h"


using namespace sf;

namespace sfp {
    class PhysicsCircle : public PhysicsShapeGlue<CenteredCircle,CircleBounds>
    {
    public:
        PhysicsCircle() : PhysicsShapeGlue<CenteredCircle, CircleBounds>(){}
        PhysicsCircle(const PhysicsCircle& other):
            PhysicsShapeGlue<CenteredCircle, CircleBounds>(other) {}
        
    };
}

