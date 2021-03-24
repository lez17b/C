//
// Created by Luciano Zavala on 06/23/2020.
//

#include <iostream>
#include <cmath>
#include "circle.h"

// **************************************************************************************
// * Function Name: Circle default constructor	                                        *
// * Description: This function is the default constructur and asigns the default       *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Circle::Circle()
{
    radius = DEFAULT_RADIUS;
}


// **************************************************************************************
// * Function Name: Circle parameter constructor	                                    *
// * Description: This function is the parameter constructor and assigns the default    *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Circle::Circle(double new_radius)
{
   SetCircleRadius(new_radius);
}

// **************************************************************************************
// * Function Name: Set circle radius function	                                        *
// * Description: This function sets the radius of the circle     .                     *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Circle::SetCircleRadius(double new_radius)
{
    if(new_radius < DEFAULT_RADIUS)
    {
        radius = DEFAULT_RADIUS;
    }
    else
        radius = new_radius;
}


// **************************************************************************************
// * Function Name: Get circle radius function	                                        *
// * Description: This function gets the radius of the circle  and returns the value.    *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Circle::GetCircleRadius() const
{
    return radius;
}

// **************************************************************************************
// * Function Name:  get shape area method  (Virtual Function)                          *
// * Description: This function gets and computes the area of the circel and returns it.*                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Circle::GetShapeArea()
{
    area = M_PI * radius * radius;
    return area;
}


// **************************************************************************************
// * Function Name:  get shape perimeter method  (Virtual Function)                     *
// * Description: This function gets and computes the perimeter of the circle and       *
// * returns it.                                                                        *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Circle::GetShapePerimeter()
{
    perimeter = 2 * M_PI * radius;
    return perimeter;
}


// **************************************************************************************
// * Function Name: Print data Fucntion (virtual function)	                            *
// * Description: This function gets the area of the shape and prints it.               *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Circle::PrintData()
{
    cout << "The Radius of the Circle is: " << GetCircleRadius() << endl;
    cout << "The Area of the Circle: " << GetShapeArea() << endl;
    cout << "The Perimeter of the Circle: " << GetShapePerimeter() << endl;
}








