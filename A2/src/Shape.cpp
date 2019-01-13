#include "../include/Shape.h"

Shape::Shape()
{
    numberArray = nullptr;
    point = nullptr;
}

Shape::~Shape()
{
    if(numberArray != nullptr)
        delete[] numberArray;
    if(point != nullptr)
        delete[] point;
    numberArray = nullptr;
    point = nullptr;
}

Shape* Shape::operator+(Shape &obj)
{
    int newSize = this->numberOfPoints + obj.numberOfPoints;
    Coord *tempCoord = new Coord[newSize];
    int count = 0;
    for(int i = 0; i < newSize; i++)
    {
        if(i < this->numberOfPoints)
        {
            tempCoord[i].x = this->point[i].x;
            tempCoord[i].y = this->point[i].y;
        }
        else
        {
            tempCoord[i].x = obj.point[count].x;
            tempCoord[i].y = obj.point[count].y;
            count++;
        }
    }
    this->numberOfPoints = newSize;
    delete [] this->point;
    point = new Coord[newSize];
    for(int i = 0; i < newSize; i++)
    {
        this->point[i] = tempCoord[i];
    }

    delete [] tempCoord;
    tempCoord = nullptr;
    return this;
}

Shape* Shape::operator=(Shape &obj)
{
    if(this == &obj)
    {
        std::cout << this << " = " << &obj << std::endl;
        return this;
    }
    else
        std::cout << this << " != " << &obj << std::endl;

    std::cout << "\n*Calling overloaded operator=*\n" << std::endl;
    delete [] point;
    point = nullptr;
    point = new Coord[obj.numberOfPoints];
    for(int i = 0; i < numberOfPoints; i++)
    {
        this->point[i].x = obj.point[i].x;
        this->point[i].y = obj.point[i].y;
    }
    return this;
}


double* Shape::getArray()
{
    numberArray = new double[numberOfPoints*2];
    int count = 0;
    for(int i = 0; i < numberOfPoints*2; i += 2)
    {
        numberArray[i] = point[count].x;
        numberArray[i+1] = point[count].y;
        count++;
    }
    return numberArray;
}

int Shape::getNumberOfElements()
{
    return numberOfPoints*2;
}
void Shape::getShapeInformation()
{
    std::cout << "----------------------------------"        << std::endl;
    std::cout << "originalType:  " << this->originalType     << std::endl;
    std::cout << "Type:          " << this->getType()        << std::endl;
    std::cout << "Area:          " << this->area()           << std::endl;
    std::cout << "Circumference: " << this->circumference()  << std::endl;
    std::cout << "CenterCoord:  (" << this->position().x << "," << this->position().y << ")\n";
    std::string ans = (isConvex()) ? "yes" : "No";
    std::cout << "Convex:        " << ans << std::endl;

    for(int i = 0; i < numberOfPoints; i++)
        std::cout << "(" << this->point[i].x << "," << this->point[i].y << ") ";

    std::cout << "\nMemory address point: " << point  << std::endl;
    std::cout << "Memory address &point: "  << &point << std::endl;
}
