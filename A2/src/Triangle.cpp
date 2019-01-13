#include "../include/Triangle.h"

Triangle::Triangle(double *array, int numberOfElements)
{
    if(numberOfElements != 6)
        numberOfElements = 6;

    this->numberOfPoints = numberOfElements / 2;
    this->point = new Coord[numberOfPoints];
    int count = 0;
    for(int i = 0; i < numberOfElements; i += 2)
    {
        this->point[count].x = array[i];
        this->point[count].y = array[i+1];
        count++;
    }
    originalType = "Triangle";
}

Triangle::~Triangle()
{

}

double Triangle::area()
{
    double area;
    area = (this->point[0].x * (this->point[1].y - this->point[2].y)  +
    this->point[1].x * (this->point[2].y - this->point[0].y)  +
    this->point[2].x * (this->point[0].y - this->point[1].y)) / 2;
    return fabs(area);
}
std::string Triangle::getType()
{
    return "Triangle";
}
double Triangle::circumference()
{
    double ab, bc, ca;
    ab = sqrt(pow(this->point[0].x - this->point[1].x,2) + pow(this->point[0].y - this->point[1].y,2));
    bc = sqrt(pow(this->point[1].x - this->point[2].x,2) + pow(this->point[1].y - this->point[2].y,2));
    ca = sqrt(pow(this->point[2].x - this->point[0].x,2) + pow(this->point[2].y - this->point[0].y,2));
    return ab + bc + ca;
}
Triangle::Coord Triangle::position()
{
    Coord centerCoord;
    centerCoord.x = (this->point[0].x + this->point[1].x + this->point[2].x) / 3;
    centerCoord.y = (this->point[0].y + this->point[1].y + this->point[2].y) / 3;
    return centerCoord;
}
bool Triangle::isConvex()
{
    return true;
}
double Triangle::distance(Shape *s)
{
    double distance;
    distance = sqrt(pow(s->position().x - this->position().x, 2) + pow(s->position().y - this->position().y, 2));
    return distance;
}
