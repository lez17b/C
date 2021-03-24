//
// Created by Luciano Zavala on 06/22/2020.
//

#ifndef ASSIGNMENT_5_SQUARE_H
#define ASSIGNMENT_5_SQUARE_H

#include "shape.h"

const double DEFAULT_LENGHT = 1.00;

class Square : public Shape {

public:
    Square();

    explicit Square(double newlenght);

    void SetSquareLenght(double newlenght);

    double GetSquareLenght() const;

    double GetShapeArea() override;

    double GetShapePerimeter() override;

    void PrintData() override;

private:
    double lenght{};

};


#endif //ASSIGNMENT_5_SQUARE_H
