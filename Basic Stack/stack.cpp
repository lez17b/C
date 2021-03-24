// Created by Luciano Zavala 03/07/2020
// ******************************************************************** 
// * Name: Stack Class                                                * 
// * Description:  A template Stack class designed to be used with    * 
// *   any simple C++ type to include floating point, double          * 
// *   floating point, character, and boolean.                        *
// *   The stack pointer, as is the convention, points to the last    * 
// *   or highest element in the array. So if you allocate 100        * 
// *   elements of type "T" then the first empty element will be 99.  * 
// * Author: Dr. David A. Gaitros and Luciano Zavala                  *
// * Date: July 05, 2020                                              *
// ********************************************************************

#include <iostream>
#include<vector>
using namespace std;

const int DEFAULTSIZE = 100;
template <class T>
class Stack {
public:
    Stack();                         // Default Constructor, stack is size 100.
    explicit Stack(int size);        // Constructor, creates stack of size "size"
    Stack(const Stack<T> & item);    // Copy constructor
    bool Full();                     // Return true if the stack is full
    bool Empty();                    // Return true if the stack is empty
    int Size();                      // Return the size of the stack
    T Top();                         // Returns the top element, does not pop it.
    bool Push (const T item);              // Put an item on the stack.
    bool Pop();                      // Pop an item off and display to std out

    friend ostream &operator <<(ostream & os, Stack<T> &s);

private:
    T * _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top{};                 // Points to the first empty node
};


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that assigns a default size of 100 to the Stack,	 *
// *   asignes the top value to 0 and creates the stack of type T.                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template <class T>
Stack<T>::Stack()
{
    _size = DEFAULTSIZE;
    _top = 0;
    _stack = new T[_size];
}


// ***************************************************************************************
// * Function Name: Parameter Constructor				                                 *
// * Description: constructor Tha creates a new stack of the size asigned by the         *
// *   Parameter, aslo assignes the top value to 0 and the type of the stack to T.       *
// * Parameter Description: Size is the size of the stack that'll be assigned.     	     *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
Stack<T>::Stack(int size)
{
    if (size < 1)
    {
        _size = DEFAULTSIZE;
    }
    else
        _size = size;

    _top = 0;
    _stack = new T[_size];
}



// ***************************************************************************************
// * Function Name: Copy Constructor						                             *
// * Description: the copy constructor has the duty of copying all the values in a stack *
// *   to another, asigning the same top, size and type of the stack T.                  *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
Stack<T>::Stack(const Stack<T> &item)
{
    _size = item._size;
    _stack = new T[item._size];
    _top = 0;

    for (int index = 0; index < item._size; index++)
    {
        _stack[index] = item._stack[index];
    }

}



// ***************************************************************************************
// * Function Name: Size            						                             *
// * Description: Returns the size of the stack.                                         *
// * Parameter Description: This function has no parameters.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
int Stack<T>::Size()
{
    return _size;
}


// ***************************************************************************************
// * Function Name: Empty            						                             *
// * Description: Returns true if the stack is empty, false if not.                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
bool Stack<T>::Empty()
{
    return _top == 0;
}


// ***************************************************************************************
// * Function Name: Full            	                	                             *
// * Description: Returns true if the stack is full, false if not.                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
bool Stack<T>::Full()
{
    return _top == _size;
}


// ***************************************************************************************
// * Function Name: Top            						                                 *
// * Description: This function return the top element assigned for each stack.          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
T Stack<T>::Top()
{
    if(_top != 0)
    {
        return _stack[_top - 1];
    }
}


// ***************************************************************************************
// * Function Name: Push            						                             *
// * Description: This function adds an element to the end of the stack, asigning new    *
// *   size, and top value.                                                              *
// * Parameter Description: The parameters on this function refer to the item to attach  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
bool Stack<T>::Push(const T item)
{
    if(!Full())
    {
        _stack[_top++] = item;
    }
    else
        cout << "Sorry there was an error, Stack overflow!" << endl;
}


// ***************************************************************************************
// * Function Name: Push            						                             *
// * Description: This function removes an element to the end of the stack, asigning new *
// *   size, and top value.                                                              *
// * Parameter Description: The parameters on this function.				             *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template<class T>
bool Stack<T>::Pop()
{
    T item;
    if(!Empty())
    {
        item = _stack[--_top];
        cout << item << endl;
    } else
        cout << "Sorry the Stack is empty" << endl;
}


