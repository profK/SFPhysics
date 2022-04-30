#pragma once
#include "pch.h"
#include "CenteredShape.h"

namespace sfp {
    class CenteredCircle :
        public CenteredShape, public CircleShape
    {
    public:
        CenteredCircle();
        virtual void setCenter(Vector2f center) override;
        virtual Vector2f getCenter() override;
        virtual void setSize(Vector2f sz) override;
        virtual Vector2f getSize() override;
    };
}

