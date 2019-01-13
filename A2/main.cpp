#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include "include/Shape.h"
#include "include/Point.h"
#include "include/Line.h"
#include "include/Triangle.h"
#include "include/Polygon.h"
#include "include/Figure.h"
void getCoordinates(double** coordinates, int* numElements, int* numberOfShapes, std::string filename);

Shape* setShape(Shape *obj, double *array = nullptr, int numberOfElements = 0)
{
    if(obj != nullptr && obj != NULL)
    {
        std::cout << "updating object.\n";
        array = obj->getArray();
        numberOfElements = obj->getNumberOfElements();
    }

    int numPoint = 2, numLine = 4, numTriangle = 6;
    if(numberOfElements == numPoint){
        std::cout << "\nCreating a point" << std::endl;
        obj = new Point(array, numberOfElements);
    }
    else if(numberOfElements == numLine){
        std::cout << "\nCreating a line" << std::endl;
        obj = new Line(array, numberOfElements);
    }
    else if(numberOfElements == numTriangle){
        std::cout << "\nCreating a Triangle" << std::endl;
        obj = new Triangle(array, numberOfElements);
    }
    else if(numberOfElements > numTriangle && numberOfElements % 2 == 0){
        std::cout << "\nCreating a polygon" << std::endl;
        obj = new Polygon(array, numberOfElements);
    }
    else
        std::cout << "\nError" << std::endl;
    return obj;
}

int main(int argc, const char *argv[])
{
    std::string filename;
    if(argc > 1)
        filename = argv[1];
    else
        filename = "list.txt";

    double** coordinates = nullptr;
    int* numElements = nullptr;
    Shape* shape = NULL;
    Shape** shapes = nullptr;

    int numberOfShapes;
    double number;
    std::ifstream inputFile;
    inputFile.open(filename);
    std::string line = "";

    if(inputFile.is_open())
    {
        numberOfShapes = 0;
        while(getline(inputFile, line))
            numberOfShapes++;

        //reset read position
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        numElements = new int[numberOfShapes] {0};
        int index = 0;
        while(getline(inputFile, line))
        {
           std::istringstream sstream(line);
           std::string myText = "";
           while(sstream >> myText)
           {
                numElements[index]++;
           }
           index++;
        }

        //reset read position
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        coordinates = new double*[numberOfShapes];

        int shapeNumber = 0;
        while(getline(inputFile, line))
        {
           index = 0;
           std::istringstream sstream(line);
           std::string myText = "";
           coordinates[shapeNumber] = new double[numElements[shapeNumber]];
           while(sstream >> myText)
           {
            coordinates[shapeNumber][index] = stod(myText);
            index++;
           }
           shapeNumber++;
        }
    }
    else
        std::cout << "error" << std::endl;

    inputFile.close();
    shapes = new Shape*[numberOfShapes] {nullptr};

    Figure grp;
    for(int i = 0; i < numberOfShapes; i++)
    {
       shapes[i] = setShape(shapes[i], coordinates[i], numElements[i]);
       shapes[i]->getShapeInformation();
       grp.addShape(shapes[i]);
    }


    for(int i = 0; i < numberOfShapes; i++)
    {
       delete [] shapes[i];
       delete [] coordinates[i];
    }
    delete [] shapes;
    delete [] coordinates;
    delete [] numElements;
    return 0;
}
