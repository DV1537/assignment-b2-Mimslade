#ifndef FIGURE_H
#define FIGURE_H
#include "Shape.h"

class Figure
{
private:
    Shape** shapes;
    Shape** closestShapes;
    int nrOfClosest;
    int nrOfShapes;
    struct Box
    {
        double x1, y1;
        double x2, y2;
    };

public:
    Figure();
    ~Figure();
    void addShape(Shape* s);
    Shape* getShape(int index) const;
    Box getBoundingBox();
    void bubbleSort(double *array, int size);
    void recursiveBubbleSort(Shape** array, double* distances, int size);
    Shape** getClosest(Shape* location, int num);
    template <typename T>
    void swap(T& first, T& second);
    Shape** getShapes() const;
    int getNumShapes() const;

};

#endif // FIGURE_H
