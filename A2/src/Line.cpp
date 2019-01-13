#include "../include/Line.h"

Line::Line(double *array, int numberOfElements)
{
    if(numberOfElements != 4)
        numberOfElements = 4;

    this->numberOfPoints = numberOfElements / 2;
    this->point = new Coord[numberOfPoints];
    int count = 0;
    for(int i = 0; i < numberOfElements; i += 2)
    {
        this->point[count].x = array[i];
        this->point[count].y = array[i + 1];
        count++;
    }
    originalType = "Line";
}

Line::~Line()
{

}

double Line::area()
{
    return 0.0;
}
std::string Line::getType()
{
    return "Line";
}
double Line::circumference()
{
    return 0.0;
}
Line::Coord Line::position()
{
    Coord centerCoord;
    centerCoord.x = (this->point[0].x + this->point[1].x) / 2;
    centerCoord.y = (this->point[0].y + this->point[1].y) / 2;
    return centerCoord;
}
bool Line::isConvex()
{
    return false;
}
double Line::distance(Shape *s)
{
    double distance;
    distance = sqrt(pow(s->position().x - this->position().x, 2) + pow(s->position().y - this->position().y, 2));
    return distance;
}
