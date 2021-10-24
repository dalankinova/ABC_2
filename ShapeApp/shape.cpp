#include "stdafx.h"
#include "shape.h"

Shape::Shape(Color color) :
    m_color(color)
{

}

Color Shape::color() const
{
    return m_color;
}

void Shape::setColor(const Color &color)
{
    m_color = color;
}
