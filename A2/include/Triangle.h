#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(double *array, int numberOfElements);
    ~Triangle();
    virtual double area() override;
    virtual std::string getType() override;
    virtual double circumference() override;
    virtual Coord position() override;
    virtual bool isConvex() override;
    virtual double distance(Shape *s) override;
};

#endif // TRIANGLE_H
