//
// Created by Luciano Zavala  on 06/23/2020.
//

#ifndef ASSIGNMENT_5_CIRCLE_H
#define ASSIGNMENT_5_CIRCLE_H

#include "shape.h"

const double DEFAULT_RADIUS = 1.00;

class Circle : public Shape {

public:
    Circle();

    explicit Circle(double new_radius);

    void SetCircleRadius(double new_radius);

    double GetCircleRadius() const;

    double GetShapeArea() override;

    double GetShapePerimeter() override;

    void PrintData() override;

private:
    double radius{};

};


#endif //ASSIGNMENT_5_CIRCLE_H
