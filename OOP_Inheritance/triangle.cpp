//
// Created b Luciano Zavala on 06/22/2020.
//

#include <iostream>
#include <cmath>
#include "triangle.h"

// **************************************************************************************
// * Function Name: Triangle default constructor	                                    *
// * Description: This function is the default constructur and asigns the default       *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Triangle::Triangle()
{
    side1 = DEFAULT_SIDE1;
    side2 = DEFAULT_SIDE2;
    side3 = DEFAULT_SIDE3;
}


// **************************************************************************************
// * Function Name: Triangle parameter constructor	                                    *
// * Description: This function is the parameter constructor and assigns the parameter  *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Triangle::Triangle(double side_1, double side_2, double side_3)
{
    SetTriangleSide1(side_1);
    SetTriangleSide2(side_2);
    SetTriangleSide3(side_3);
}

// **************************************************************************************
// * Function Name: Set Triangle's side length function	                                *
// * Description: This function sets the the length of one of the sides of the square   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Triangle::SetTriangleSide1(double side_1)
{
    if(side_1 < DEFAULT_SIDE1)
    {
        side1 = DEFAULT_SIDE1;
    }
    else
        side1 = side_1;
}


// **************************************************************************************
// * Function Name: Set Triangle's side length function	                                *
// * Description: This function sets the the length of one of the sides of the square   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Triangle::SetTriangleSide2(double side_2)
{
    if(side_2 < DEFAULT_SIDE2)
    {
        side2 = DEFAULT_SIDE2;
    }
    else
        side2 = side_2;
}


// **************************************************************************************
// * Function Name: Set Triangle's side length function	                                *
// * Description: This function sets the the length of one of the sides of the square   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Triangle::SetTriangleSide3(double side_3)
{
    if(side_3 < DEFAULT_SIDE3)
        side3 = DEFAULT_SIDE3;
    else
        side3 = side_3;
}


// **************************************************************************************
// * Function Name:  get triangle side length method                                    *
// * Description: This function gets the length of the triangle's side and returns it.  *                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Triangle::GetTriangleSide1() const {
    return side1;
}


// **************************************************************************************
// * Function Name:  get triangle side length method                                    *
// * Description: This function gets the length of the triangle's side and returns it.  *                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Triangle::GetTriangleSide2() const {
    return side2;
}


// **************************************************************************************
// * Function Name:  get triangle side length method                                    *
// * Description: This function gets the length of the triangle's side and returns it.  *                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Triangle::GetTriangleSide3() const {
    return side3;
}


// ****************************************************************************************
// * Function Name:  get shape area method  (Virtual Function)                            *
// * Description: This function gets and computes the area of the triangle and returns it.*                                                  *
// * Date: 06/23/2020									                                  *
// * Author: Luciano Zavala        							                              *
// * References: Videos by david Gaitros on inheritance                                   *
// ****************************************************************************************


double Triangle::GetShapeArea()
{
    double sides, formula;

    sides = (side1 + side2 + side3)/2;
    formula = sides * (sides-side1) * (sides - side2) * (sides - side3);
    area = sqrt(abs(formula));

    return area;
}


// **************************************************************************************
// * Function Name:  get shape perimeter method  (Virtual Function)                     *
// * Description: This function gets and computes the perimeter of the square and       *
// * returns it.                                                                        *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Triangle::GetShapePerimeter()
{
    perimeter = side1 + side2 + side3;
    return perimeter;
}


// **************************************************************************************
// * Function Name: Print data Fucntion (virtual function)	                            *
// * Description: This function gets the area of the shape and prints it.               *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Triangle::PrintData()
{
    cout << "The lenght of the first side is :" << GetTriangleSide1() << endl;
    cout << "The lenght of the second side is :" << GetTriangleSide2() << endl;
    cout << "The lenght of the third side is :" << GetTriangleSide3() << endl;
    cout << "The Area of the Triangle: " << GetShapeArea() << endl;
    cout << "The Perimeter of the Triangle: " << GetShapePerimeter() << endl;
}






