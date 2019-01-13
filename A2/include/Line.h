#ifndef LINE_H
#define LINE_H

#include "Shape.h"


class Line : public Shape
{
public:
    Line(double *array, int numberOfElements);
    ~Line();
    virtual double area() override;
    virtual std::string getType() override;
    virtual double circumference() override;
    virtual Coord position() override;
    virtual bool isConvex() override;
    virtual double distance(Shape *s) override;

};

#endif // LINE_H
