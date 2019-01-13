#include "../include/Point.h"

Point::Point(double *array, int numberOfElements)
{
    if(numberOfElements != 2)
        numberOfElements = 2;

    this->numberOfPoints = numberOfElements / 2;
    this->point = new Coord[numberOfPoints];
    int count = 0;
    for(int i = 0; i < numberOfElements; i += 2)
    {
        this->point[count].x = array[i];
        this->point[count].y = array[i + 1];
        count++;
    }
    originalType = "Point";
}

Point::~Point()
{

}

double Point::area()
{
    return 0;
}

std::string Point::getType()
{
    return "Point";
}

double Point::circumference()
{
    return 0.0;
}

Point::Coord Point::position()
{
    return point[0];
}
bool Point::isConvex()
{
    return false;
}

double Point::distance(Shape *s)
{
    double distance;
    distance = sqrt(pow(s->position().x - this->position().x, 2) + pow(s->position().y - this->position().y, 2));
    return distance;
}


