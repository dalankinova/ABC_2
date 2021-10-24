#pragma once

#include "shape.h"

class Circle : public Shape
{
public:
    Circle(double radius, Point centre, Color color);
    virtual double calcArea();

    double radius() const;
    void setRadius(double radius);

    Point centre() const;
    void setCentre(const Point &centre);

private:
    Point m_centre;
    double m_radius;
};
