#pragma once
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(Point topLeft, Point bottomRight, Color color);
    virtual double calcArea();
    Point topLeft() const;
    void setTopLeft(const Point &topLeft);

    Point bottomRight() const;
    void setBottomRight(const Point &bottomRight);

private:
    Point m_topLeft;
    Point m_bottomRight;
};