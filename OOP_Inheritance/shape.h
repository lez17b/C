//
// Created by Luciano zavala on 06/22/2020.
//

#ifndef ASSIGNMENT_5_SHAPE_H
#define ASSIGNMENT_5_SHAPE_H
#include <string>
using namespace std;

const double DEFAULT_AREA = 1.00;
const double DEFAULT_PERIMETER = 1.00;

class Shape{

public:
    Shape();

    Shape(double area, double perimeter);

    void SetShapeArea(double area);

    void SetShapePerimeter(double perimeter);

    virtual double GetShapeArea();

    virtual double GetShapePerimeter();

    virtual void PrintData();

protected:
    double area{};
    double perimeter{};

};


#endif //ASSIGNMENT_5_SHAPE_H
