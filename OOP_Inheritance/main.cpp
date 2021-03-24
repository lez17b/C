#include <iostream>
#include "shape.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
using namespace std;

// *******************************************************************************
// * Author: Luciano Zavala                                                      *
// * File Name: main.cpp (Assignment 5)                                          *
// * Course: COP3330                                                             *
// * Description: The main is designed to test the Inheritance of the shapes.    *
// * Instructor: Dr. Jeremy Hatcher					                             *
// * Date: 06/24/2020                                                            *
// *******************************************************************************

int main() {

    //FATHER SHAPE TEST
    cout << "\nDefault father Shape:" << endl;
    cout << "The default Constructor is:" << endl;
    Shape myShape1;
    myShape1.PrintData();
    cout<<endl;

    cout << "The parameter constructor with valid sizes:" << endl;
    Shape myShape2(13, 20);
    myShape2.PrintData();
    cout << endl;

    cout << "The parameter constructor with invalid sizes:" << endl;
    Shape myShape3(-1, -1);
    myShape3.PrintData();
    cout << endl << endl;


    //SQUARE TEST
    cout << "Square shape:" << endl;
    cout << "The default Constructor is:" << endl;
    Square mySquare1;
    mySquare1.PrintData();
    cout<<endl;

    cout << "The parameter constructor TEST with valid sizes:" << endl;
    Square mySquare2(20);
    mySquare2.PrintData();
    cout << endl;

    cout << "The parameter constructor TEST with invalid sizes:" << endl;
    Square mySquare3(-1);
    mySquare3.PrintData();
    cout << endl << endl;


    //RECTANGLE TEST
    cout << "Rectangle shape:" << endl;
    cout << "The default Constructor TEST:" << endl;
    Rectangle myRectangle1;
    myRectangle1.PrintData();
    cout<<endl;

    cout << "The parameter constructor with valid sizes:" << endl;
    Rectangle myRectangle2(3.0, 5.4);
    myRectangle2.PrintData();
    cout << endl;

    cout << "The parameter constructor with invalid sizes:" << endl;
    Rectangle myRectangle3(-1, -1);
    myRectangle3.PrintData();
    cout << endl << endl;


    // CIRCLE TEST
    cout << "Circle shape:" << endl;
    cout << "The default Constructor:" << endl;
    Circle myCircle1;
    myCircle1.PrintData();
    cout<<endl;

    cout << "The parameter constructor with valid sizes:" << endl;
    Circle myCircle2(20);
    myCircle2.PrintData();
    cout << endl;

    cout << "The parameter constructor TEST with invalid sizes:" << endl;
    Circle myCircle3(-1);
    myCircle3.PrintData();
    cout << endl << endl;


    //TRIANGLE TEST
    cout << "Triangle shape:" << endl;
    cout << "The default Constructor TEST:" << endl;
    Triangle myTriangle1;
    myTriangle1.PrintData();
    cout<<endl;

    cout << "The parameter constructor TEST with valid sizes:" << endl;
    Triangle myTriangle2(1.5, 4.50, 5.00);
    myTriangle2.PrintData();
    cout << endl;

    cout << "The parameter constructor TEST with invalid sizes:" << endl;
    Triangle myTriangle3(-1, -1, -1);
    myTriangle3.PrintData();
    cout << endl << endl;

    return 0;
}
