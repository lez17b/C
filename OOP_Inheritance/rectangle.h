//
// Created by Luciano Zavala on 06/22/2020.
//

#ifndef ASSIGNMENT_5_RECTANGLE_H
#define ASSIGNMENT_5_RECTANGLE_H

#include "shape.h"

const double DEFAULT_BASE = 1.00,
             DEFAULT_HEIGHT = 1.00;

class Rectangle : public Shape {

public:
    Rectangle();

    Rectangle(double new_base, double new_height);

    void SetRectangleBase(double new_base);

    void SetRectangleHeight(double new_height);

    double GetRectangleBase() const;

    double GetRectangleHeight() const;

    double GetShapeArea() override;

    double GetShapePerimeter() override;

    void PrintData() override;

private:
    double base{};
    double height{};

};


#endif //ASSIGNMENT_5_RECTANGLE_H
