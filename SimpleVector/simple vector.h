//
// Created by Luciano Zavala on 7/2/20.
//

#ifndef UNTITLED98_SIMPLEVECTOR_H
#define UNTITLED98_SIMPLEVECTOR_H


#include <iostream>
#include <new>
#include <cstdlib>
#include <stdexcept>
using namespace std;

template <class T>
class SimpleVector {
private:
    T *aptr;
    int arraysize;
    void memError();
    void subError();
public:

    SimpleVector()
    {
        aptr = 0;
        arraysize = 0;
    }

    SimpleVector(int s);

    SimpleVector(const SimpleVector &);

    ~SimpleVector();

    int size() const
    {
        return arraysize;
    }

    T getElementAt(int sub);

    T & operator[](const int & index);

};


#endif //UNTITLED98_SIMPLEVECTOR_H

// ******************************************************************************************
// * Function Name: SimpleVector<T>::SimpleVector(int s)                                    *
// * Description: Class constructor accepts an integer and stores it as the size.           *
// *              If the size is less than 1, the function will make the size to one        *
// *              In case memory is not allocated, the function will call for memError      *
// *              and display an error. It also initializes all the                         *
// *              elements in the array to be zeros.                                        *
// * Parameter Description: int s is passed in as the user's desired size for the array     *
// * Date: July 2, 2020                                                                     *
// * Author: Luciano Zavala                                                                 *
// * References: Dr. David Gaitros Assignment #6 Explanation Video                          *
// ******************************************************************************************


template <class T>
SimpleVector<T>::SimpleVector(int s) {
    if (s < 1)
        arraysize = 1;
    else
        arraysize = s;
    try {
        aptr = new T [arraysize];
    }
    catch (bad_alloc) {
        memError();
    }
    for (int index = 0; index < arraysize; index++)
        aptr[index] = 0;
}


// ******************************************************************************************
// * Function Name: SimpleVector<T>::SimpleVector(const SimpleVector & s)                   *
// * Description: Class copy constructor accepts a class and also copies its elements       *
// *              into a new object. It assigns the size of the array that is passed        *
// *              to the size of the new array. It allocates space for the array.           *
// *              Finally, it copies all of its element to the new array.                   *
// * Parameter Description: const SimpleVector & s is passed in as an existing object       *
// *                        in which all of its elements are passed in to the new object.   *
// * Date: July 02, 2020                                                                    *
// * Author: Luciano Zavala                                                                 *
// * References: Dr. David Gaitros Conference Session, referenced to the BitVector          *
// *             assignment                                                                 *
// ******************************************************************************************


template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector & s)
{
    arraysize = s.arraysize;
    aptr = new T[s.arraysize];
    for (int index = 0; index < s.arraysize; index++)
    {
        aptr[index] = s.aptr[index];
    }
}


// ******************************************************************************************
// * Function Name: SimpleVector<T>::~SimpleVector()                                        *
// * Description: Class destructor that points the aptr to nullptr and also destroys the    *
// *              object.                                                                   *
// * Parameter Description: None                                                            *
// * Date: July 02, 2020                                                                    *
// * Author: Luciano Zavala                                                                 *
// * References: Reference taken from Bitvector code.                                       *
// ******************************************************************************************


template <class T>
SimpleVector<T>::~SimpleVector()
{
    delete[] aptr;
    aptr = nullptr;
}


// ******************************************************************************************
// * Function Name: T & SimpleVector<T>::operator[](const int & index)                      *
// * Description: Square brackets operator overloading. Returns the element in the array    *
// *              according to the index that is passed in. If the index is out of range,   *
// *              it will call on subError.                                                 *
// * Parameter Description: const int & index is being passed in as the index of the array  *
// * Date: July 02, 2020                                                                    *
// * Author: Luciano Zavala                                                                 *
// * References:                                                                            *
// ******************************************************************************************


template <class T>
T & SimpleVector<T>::operator[](const int & index)
{
    if (index < arraysize)
    {
        return aptr[index];
    }
    else
        subError();
}


// ******************************************************************************************
// * Function Name: T SimpleVector<T>::getElementAt(int sub)                                *
// * Description: Class accessor function, returns the element in the array. The            *
// *              subscript is being passed in to get the specific element. It also         *
// *              validates that the subscript is in rage; otherwise, it will call the      *
// *              subError() and displays an error that it is trying to access an element   *
// *              that is out of range.                                                     *
// * Parameter Description: int sub is being passed in as the subscript of the array in     *
// *                        which the user wants to access.                                 *
// * Date: July 02, 2020                                                                    *
// * Author: Luciano Zavala                                                                 *
// * References:                                                                            *
// ******************************************************************************************


template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < arraysize)
    {
        return aptr[sub];
    }
    else
        subError();
}


// ***********************************************************************************************
// * Function Name: void SimpleVector<T>::memError()                                             *
// * Description: Class private function that displays that memory  is not correctly allocated.  *
// *              After displaying the message, the program exists.                              *
// * Parameter Description: None                                                                 *
// * Date: July 02, 2020                                                                         *
// * Author: Luciano zavala                                                                      *
// * References: Dr. David Gaitros Assignment #6 Explanation Video                               *
// ***********************************************************************************************


template <class T>
void SimpleVector<T>::memError()
{
    cout << "Error: cannot allocate memory." << endl;
    exit(EXIT_FAILURE);
}


// ******************************************************************************************
// * Function Name: void SimpleVector<T>::subError()                                        *
// * Description: Class private function that displays that the subscript is out of range.  *
// * Parameter Description: None                                                            *
// * Date: July 02, 2020                                                                    *
// * Author: Luciano Zavala                                                                 *
// * References: Dr. David Gaitros Assignment #6 Explanation Video                          *
// ******************************************************************************************


template <class T>
void SimpleVector<T>::subError()
{
    cout << "Error: subscript is out of range." << endl;
    exit(EXIT_FAILURE);
}

