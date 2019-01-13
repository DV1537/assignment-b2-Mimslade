#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
#include <cmath>
class Shape
{
protected:
    struct Coord
    {
        double x;
        double y;
    };
    std::string originalType;
    Coord *point;
    int numberOfPoints;
    double *numberArray;
    int c;
public:
    Shape();
    virtual ~Shape();
    virtual double area() = 0;
    virtual std::string getType() = 0;
    virtual double circumference() = 0;
    virtual Coord position() = 0;
    virtual bool isConvex() = 0;
    virtual double distance(Shape *s) = 0;

    Shape* operator=(Shape &obj);
    Shape* operator+(Shape &obj);

    double *getArray();
    int getNumberOfElements();
    void getShapeInformation();
};

#endif // SHAPE_H
