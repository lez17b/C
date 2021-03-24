//
// Created by Luciano Zavala on 06/22/2020.
//

#ifndef ASSIGNMENT_5_TRIANGLE_H
#define ASSIGNMENT_5_TRIANGLE_H

#include "shape.h"

const double DEFAULT_SIDE1 = 1.00, DEFAULT_SIDE2 = 1.00, DEFAULT_SIDE3 = 1.00;

class Triangle : public Shape {

public:
    Triangle();

    Triangle(double s1, double s2, double s3);

    void SetTriangleSide1(double s1);

    void SetTriangleSide2(double s2);

    void SetTriangleSide3(double s3);

    double GetTriangleSide1() const;

    double GetTriangleSide2() const;

    double GetTriangleSide3() const;

    double GetShapeArea() override;

    double GetShapePerimeter() override;

    void PrintData() override;

private:
    double side1{};
    double side2{};
    double side3{};

};


#endif //ASSIGNMENT_5_TRIANGLE_H
