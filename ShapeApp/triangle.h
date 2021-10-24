#pragma once
#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(Point first, Point second, Point third, Color color);
    virtual double calcArea();
    Point first() const;
    void setFirst(const Point &first);

    Point second() const;
    void setSecond(const Point &second);

    Point third() const;
    void setThird(const Point &third);

private:
    Point m_first;
    Point m_second;
    Point m_third;
};
