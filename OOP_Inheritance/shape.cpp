//
// Created by Luciano Zavala on 06/22/2020.
//

#include <iostream>
#include "shape.h"

// **************************************************************************************
// * Function Name: Shape Default Constructor     		                                *
// * Description: Implements the default constructor.                                   *
// * Date: 06/24/2020									                                *
// * Author: Luciano Zavala         							                        *
// * References:                                                                        *
// *             Dr. Gaitros' videos and lectures.                                      *
// **************************************************************************************

Shape::Shape()
{
    area = DEFAULT_AREA;
    perimeter = DEFAULT_PERIMETER;
}

// **************************************************************************************
// * Function Name: Shape (Parameter constructor)				                        *
// * Description: Implements the parameter constructor                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: videos by dr. David gaitros                                            *
// **************************************************************************************

Shape::Shape(double area, double perimeter)
{

    SetShapeArea(area);

    SetShapePerimeter(perimeter);

}

// **************************************************************************************
// * Function Name: Set shape area Function					                            *
// * Description: This function sets the area and if its less than 0 it assigns the     *
// * default value.                                                                     *
// * Date: 06/24/2020									                                *
// * Author: Luciano Zavala          							                        *
// * References: Videos by Dr. david Gaitros on inheritance                             *
// **************************************************************************************


void Shape::SetShapeArea(double N_area)
{
    if(N_area < DEFAULT_AREA)
    {
        area = DEFAULT_AREA;
    }
    else
        area = N_area;
}


// **************************************************************************************
// * Function Name: Set shape perimeter function	                                    *
// * Description: Thic function set the perimeter of the shape and asigns the default   *
// * value if its less than zero.                                                       *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Shape::SetShapePerimeter(double new_perimeter)
{
    if(new_perimeter < DEFAULT_PERIMETER)
    {
        perimeter = DEFAULT_PERIMETER;
    }
    else
        perimeter = new_perimeter;
}


// **************************************************************************************
// * Function Name: Get shape Area function	                                            *
// * Description: This function gets the area of the shape                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Shape::GetShapeArea()
{
    return area;
}


// **************************************************************************************
// * Function Name: Get shape perimeter function	                                    *
// * Description: This function gets and returns the perimeter of the shape.            *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Shape::GetShapePerimeter()
{
    return perimeter;
}


// **************************************************************************************
// * Function Name: Print data Function (virtual function)	                            *
// * Description: This function gets the area of the shape and prints it.               *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************



void Shape::PrintData()
{
    cout << "The Area of the Shape is: " << GetShapeArea() << endl;
    cout << "The Perimeter of the Shape is: " << GetShapePerimeter()  << endl;
}


















