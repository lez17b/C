//
// Created by Luciano Zavala on 06/23/2020.
//

#include <iostream>
#include "rectangle.h"

// **************************************************************************************
// * Function Name: rectangle default constructor	                                    *
// * Description: This function is the adefault constructur and asigns the default       *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Rectangle::Rectangle()
{
    base = DEFAULT_BASE;
    height = DEFAULT_HEIGHT;
}


// **************************************************************************************
// * Function Name: square parameter constructor	                                    *
// * Description: This function is the parameter constructor and assigns the default    *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Rectangle::Rectangle(double new_base, double new_height)
{
    SetRectangleBase(new_base);
    SetRectangleHeight(new_height);
}


// **************************************************************************************
// * Function Name: Set rectangle base function	                                        *
// * Description: This function sets the the base of the rectangle.                     *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Rectangle::SetRectangleBase(double new_base)
{
    if(new_base < DEFAULT_BASE)
    {
        base = DEFAULT_BASE;
    }
    else
        base = new_base;
}


// **************************************************************************************
// * Function Name: Set rectangle height function	                                    *
// * Description: This function sets the the height of the rectangle.                   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Rectangle::SetRectangleHeight(double new_height)
{
    if(new_height < DEFAULT_HEIGHT)
    {
        height = DEFAULT_HEIGHT;
    }
    else
        height = new_height;
}


// **************************************************************************************
// * Function Name: Get rectangle base function	                                        *
// * Description: This function gets the the base of the rectangle.                     *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Rectangle::GetRectangleBase() const
{
    return base;
}

// **************************************************************************************
// * Function Name: Set rectangle height function	                                    *
// * Description: This function sets the the height of the rectangle.                   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Rectangle::GetRectangleHeight() const
{
    return height;
}


// **************************************************************************************
// * Function Name:  get shape area method  (Virtual Function)                          *
// * Description: This function gets and computes the area of the square and returns it.*                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Rectangle::GetShapeArea(){
    area = base*height;

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


double Rectangle::GetShapePerimeter(){
    perimeter = 2*base + 2*height;

    return perimeter;
}


// **************************************************************************************
// * Function Name: Print data Fucntion (virtual function)	                            *
// * Description: This function gets the area of the shape and prints it.               *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Rectangle::PrintData()
{
    cout << "The lenght of the Rectangle's Base is: " << GetRectangleBase() << endl;
    cout << "The lenght of the Rectangle's Height is: " << GetRectangleHeight() << endl;
    cout << "The Area of the Rectangle: " << GetShapeArea() << endl;
    cout << "The Perimeter of the Rectangle: " << GetShapePerimeter() << endl;
}




