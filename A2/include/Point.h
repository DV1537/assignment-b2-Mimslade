#ifndef POINT_H
#define POINT_H

#include "Shape.h"


class Point : public Shape
{
public:
    Point(double *array, int numberOfElements);
    ~Point();
    virtual double area() override;
    virtual std::string getType() override;
    virtual double circumference() override;
    virtual Coord position() override;
    virtual bool isConvex() override;
    virtual double distance(Shape *s) override;
};

#endif // POINT_H
