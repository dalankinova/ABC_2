#include <iostream>
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;

void shellSort(Shape **arr, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            Shape *temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap]->calcArea() > temp->calcArea(); j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

Color getColor(string color)
{
    Color colorClass;

    if (color == "red")
        colorClass = Color::Red;
    else if (color == "blue")
        colorClass = Color::Blue;
    else if (color == "green")
        colorClass = Color::Green;
    else if (color == "orange")
        colorClass = Color::Orange;
    else if (color == "purple")
        colorClass = Color::Purple;
    else if (color == "yellow")
        colorClass = Color::Yellow;
    else if (color == "darkblue")
        colorClass = Color::Dark_Blue;

    return colorClass;
}

void readFile(const string &filename, Shape **arr, int *size)
{
    *size = 0;
    ifstream in(filename, ios::in);

    string line;
    istringstream iss;
    while (getline(in, line)) {
        string type;
        istringstream iss(line);
        iss >> type;
        if (type == "Rectangle") {
            Point topLeft, bottomRight;
            iss >> topLeft.x >> topLeft.y >> bottomRight.x >> bottomRight.y;
            string color;
            iss >> color;
            arr[(*size)++] = new Rectangle(topLeft, bottomRight, getColor(color));
        } else if (type == "Circle") {
            Point centre;
            double radius;
            iss >> centre.x >> centre.y >> radius;
            string color;
            iss >> color;
            arr[(*size)++] = new Circle(radius, centre, getColor(color));
        }  else if (type == "Triangle") {
            Point first, second, third;
            iss >> first.x >> first.y >> second.x >> second.y >> third.x >> third.y;
            string color;
            iss >> color;
            arr[(*size)++] = new Triangle(first, second, third, getColor(color));
        }
    }
    in.close();
}


void writeFile(const string &filename, Shape **arr, int size)
{
    ofstream out(filename, ios::out | ios::app);

    out << "SIZE = " << size << endl;

    for (int i = 0; i < size; ++i) {
        string color;
        switch(arr[i]->color()) {
        case Color::Red:
            color = "red";
            break;
        case Color::Blue:
            color = "blue";
            break;
        case Color::Green:
            color = "green";
            break;
        case Color::Orange:
            color = "orange";
            break;
        case Color::Purple:
            color = "purple";
            break;
        case Color::Yellow:
            color = "yellow";
            break;
        case Color::Dark_Blue:
            color = "darkblue";
            break;
        }
        if (dynamic_cast<Rectangle*>(arr[i])) {
            Rectangle *rect = dynamic_cast<Rectangle*>(arr[i]);
            out << "Rectangle: TopLeft(" << rect->topLeft().x << ";" << rect->topLeft().y << "), BottomRight(" <<
                   rect->bottomRight().x << ";" << rect->bottomRight().y << ") Area=" <<
                   rect->calcArea() << " " << color << endl;
        } else if (dynamic_cast<Circle*>(arr[i])) {
            Circle *circle = dynamic_cast<Circle*>(arr[i]);
            out << "Circle: centre(" << circle->centre().x << ";" << circle->centre().y << "), radius= " <<
                   circle->radius() << ", Area=" << circle->calcArea() << " " << color << endl;
        } if (dynamic_cast<Triangle*>(arr[i])) {
            Triangle *triangle = dynamic_cast<Triangle*>(arr[i]);
            out << "Triangle: First(" << triangle->first().x << ";" << triangle->first().y << "), Second(" <<
                   triangle->second().x << ";" << triangle->second().y << "), Third(" <<
                   triangle->third().x << ";" << triangle->third().y << "), Area=" <<
                   triangle->calcArea()  << " " << color << endl;
        }
    }
    out.close();

}

int main(int argc, char **argv)
{
    if (argc < 3)
        return -1;

    const int SIZE = 100000;
    int count = 0;

    Shape *array[SIZE];
    readFile(argv[1], array, &count);

    writeFile(argv[2], array,count);

    shellSort(array, count);

    writeFile(argv[2], array,count);

    return 0;
}
