#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"


class Polygon : public Shape
{
public:
    Polygon(double *array, int numberOfElements);
    ~Polygon();

    virtual double area() override;
    virtual std::string getType() override;
    virtual double circumference() override;
    virtual Coord position() override;
    virtual bool isConvex() override;
    virtual double distance(Shape *s) override;
};

#endif // POLYGON_H
