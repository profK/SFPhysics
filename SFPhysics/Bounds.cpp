#include "pch.h"
#include "Bounds.h"
#include <iostream>

Vector2f sfp::Bounds::getPosition()
{
    return Vector2f(0, 0);
}

void sfp::Bounds::visualize(RenderWindow& window)
{
    std::cout << "Visualize undefined " << std::endl;
}
