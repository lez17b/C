//
// Created by Luciano Zavala on 06/23/2020.
//

#include <iostream>
#include "square.h"


// **************************************************************************************
// * Function Name: square default constructor	                                        *
// * Description: This function is the default constructur and asigns the default       *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Square::Square()
{
    lenght = DEFAULT_LENGHT;
}


// **************************************************************************************
// * Function Name: square parameter constructor	                                    *
// * Description: This function is the parameter constructor and assigns the default    *
// * values to the object.                                                              *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


Square::Square(double lenght)
{
    SetSquareLenght(lenght);
}


// **************************************************************************************
// * Function Name: Set square length function	                                        *
// * Description: This function sets the the length of one of the sides of the square   *                                                             *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Square::SetSquareLenght(double New_length)
{
    if(New_length < DEFAULT_LENGHT)
    {
        lenght = DEFAULT_LENGHT;
    }
    else
        lenght = New_length;
}


// **************************************************************************************
// * Function Name:  get square length method                                           *
// * Description: This function gets the length of the square and returns it.           *                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Square::GetSquareLenght() const
{
    return lenght;
}


// **************************************************************************************
// * Function Name:  get shape area method  (Virtual Function)                          *
// * Description: This function gets and computes the area of the square and returns it.*                                                  *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


double Square::GetShapeArea()
{
    area = lenght * lenght;

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


double Square::GetShapePerimeter()
{
    perimeter = 4 * lenght;

    return perimeter;
}


// **************************************************************************************
// * Function Name: Print data Fucntion (virtual function)	                            *
// * Description: This function gets the area of the shape and prints it.               *
// * Date: 06/23/2020									                                *
// * Author: Luciano Zavala        							                            *
// * References: Videos by david Gaitros on inheritance                                 *
// **************************************************************************************


void Square::PrintData()
{
    cout << "The Length of the Square sides: " << GetSquareLenght() << endl;
    cout << "The Area of the Square: " << GetShapeArea() << endl;
    cout << "The Perimeter of the Square: " << GetShapePerimeter() << endl;
}




