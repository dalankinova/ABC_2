#pragma once
#include <string>

enum class  Color {Red, Orange, Yellow, Green, Blue, Dark_Blue, Purple };

struct Point
{
    int x;
    int y;
    Point() {}
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Shape
{
public:
    Shape(Color color);
    virtual ~Shape() {}
    virtual double calcArea() = 0;
    Color color() const;
    void setColor(const Color &color);

protected:
    Color m_color;
};
