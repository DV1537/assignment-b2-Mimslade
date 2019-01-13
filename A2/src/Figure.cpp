#include "../include/Figure.h"

Figure::Figure()
{
    nrOfShapes = 0;
    shapes = nullptr;
    closestShapes = nullptr;
}

Figure::~Figure()
{
    delete[] shapes;
    delete[] closestShapes;
}

void Figure::addShape(Shape* s)
{
    nrOfShapes++;
    if(shapes != nullptr)
    {
        Shape** tempArray = new Shape*[nrOfShapes];
        for(int i = 0; i < nrOfShapes; i++)
        {
            if(i != nrOfShapes - 1)
                tempArray[i] = shapes[i];
            else
                tempArray[i] = s;
        }
        delete[] shapes;
        shapes = new Shape*[nrOfShapes];
        for(int i = 0; i < nrOfShapes; i++)
            shapes[i] = tempArray[i];
        delete[] tempArray;
    }
    else
    {
        shapes = new Shape*[nrOfShapes];
        shapes[0] = s;
    }

}

Shape* Figure::getShape(int index) const
{
    return shapes[index];
}

Figure::Box Figure::getBoundingBox()
{
    Box boundingBox;
    int totalSize = 0;
    for(int i = 0; i < nrOfShapes; i++)
    {
        totalSize += shapes[i]->getNumberOfElements();
    }
    int numberOfPoints = totalSize /2;
    double *xCoords = new double[numberOfPoints];
    double *yCoords = new double[numberOfPoints];
    int xCount = 0, yCount = 0;
    for(int y = 0; y < nrOfShapes; y++)
    {
        for(int x = 0; x < shapes[y]->getNumberOfElements(); x++)
        {
            if(x % 2 == 0)
                xCoords[xCount++] = shapes[y]->getArray()[x]; //all even stores in xCoords
            else
                yCoords[yCount++] = shapes[y]->getArray()[x]; //all odd stores in yCoords
        }
    }
    bubbleSort(xCoords, numberOfPoints);
    bubbleSort(yCoords, numberOfPoints);

    boundingBox.x1 = xCoords[0];
    boundingBox.y1 = yCoords[numberOfPoints - 1];
    boundingBox.x2 = xCoords[numberOfPoints - 1];
    boundingBox.y2 = yCoords[0];

    return boundingBox;
}

Shape** Figure::getClosest(Shape* location, int num)
{

    double *distances = new double[nrOfShapes];
    for (int i = 0; i < nrOfShapes; i++)
    {
        distances[i] = shapes[i]->distance(location);
    }
    recursiveBubbleSort(shapes, distances, nrOfShapes);
    if(num > nrOfShapes)
        return shapes;
    if(closestShapes != nullptr)
        delete[] closestShapes;

    closestShapes = new Shape*[num];
    this->nrOfClosest = num;
    for(int i = 0; i < num; i++)
    {
        closestShapes[i] = shapes[i];
    }
    delete[] distances;
    return closestShapes;
}

void Figure::bubbleSort(double *array, int size)
{
    bool madeAChange;
    do
    {
        madeAChange = false;
        for(int i = 0; i < size - 1; i++)
        {
            if(array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                madeAChange = true;
            }
        }

    }
    while(madeAChange);
}

void Figure::recursiveBubbleSort(Shape** array, double* distances, int size)
{
    //Base case c:
    if(size == 1)
        return;

    for(int i = 0; i < size -1; i++)
    {
        if(distances[i] > distances[i+1])
        {
            swap(distances[i], distances[i + 1]);
            swap(shapes[i], shapes[i + 1]);
        }
    }
    recursiveBubbleSort(array, distances, size - 1);
}

template <typename T>
void Figure::swap(T& first, T&second)
{
    T temp = first;
    first = second;
    second = temp;
}

Shape** Figure::getShapes() const
{
    return shapes;
}

int Figure::getNumShapes() const
{
    return nrOfShapes;

}
