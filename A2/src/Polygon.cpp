#include "../include/Polygon.h"

Polygon::Polygon(double *array, int numberOfElements)
{
    this->numberOfPoints = numberOfElements / 2;
    this->point = new Coord[numberOfPoints];
    int count = 0;
    for(int i = 0; i < numberOfElements; i += 2)
    {
        this->point[count].x = array[i];
        this->point[count].y = array[i+1];
        count++;
    }
    originalType = "Polygon";
}

Polygon::~Polygon()
{

}

double Polygon::area()
{
    if(!isConvex())
        return -1;

    double area = 0.0;
    int j = numberOfPoints;
    for(int i = 0; i < numberOfPoints; i++)
    {
        area += ((this->point[(i+1) % numberOfPoints].x + this->point[i].x) * (this->point[(i+1) % numberOfPoints].y - this->point[i].y));
    }
    area = fabs(area/2.0);
    return area;
}
std::string Polygon::getType()
{
    return "Polygon";
}
double Polygon::circumference()
{
    double circumference = 0;
    Coord startPoint = point[0];
    double length;
    for(int i = 0; i < numberOfPoints; i++)
    {
        length = sqrt(pow(this->point[i].x - this->point[(i + 1) % numberOfPoints].x,2) + pow(this->point[i].y - this->point[(i + 1) % numberOfPoints].y,2));
        circumference += length;
    }
    return circumference;
}
Polygon::Coord Polygon::position()
{
    Coord centerCoord;
    double minX, minY, maxX, maxY;
    minX = this->point[0].x;
    maxX = this->point[0].x;
    minY = this->point[0].y;
    maxY = this->point[0].y;

    for(int i = 0; i < numberOfPoints; i++)
    {
        if(this->point[i].x < minX)
            minX = this->point[i].x;
        if(this->point[i].x > maxX)
            maxX = this->point[i].x;
        if(this->point[i].y < minY)
            minY = this->point[i].y;
        if(this->point[i].y > maxY)
            maxY = this->point[i].y;
    }
    double CenterWidth = ((maxX - minX)/2) + minX;
    double CenterHeight = ((maxY - minY)/2) + minY;
    centerCoord = {CenterWidth, CenterHeight};
    return centerCoord;
}
bool Polygon::isConvex()
{
    double x1, y1, x2, y2, z;
    bool positive = false,
    negative = false;
    int size = numberOfPoints;
    for(int i = 0; i < numberOfPoints; i++)
    {
        x1 = this->point[(i+1) % size].x - this->point[i].x;
        y1 = this->point[(i+1) % size].y - this->point[i].y;
        x2 = this->point[(i+2) % size].x - this->point[(i+1) % size].x;
        y2 = this->point[(i+2) % size].y - this->point[(i+1) % size].y;
        z = (x1*y2 - y1*x2);
        if(z >= 0)
            positive = true;
        else
            negative = true;
    }
    if(positive && negative)
        return false;
    else
        return true;
}
double Polygon::distance(Shape *s)
{
    double distance;
    distance = sqrt(pow(s->position().x - this->position().x, 2) + pow(s->position().y - this->position().y, 2));
    std::cout << "Distance from shape A to Shape B is: " << distance << std::endl;
    return distance;
}
