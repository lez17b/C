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
#include "stack.cpp"
using namespace std;

 int main(void)

    {
      cout << "Assignment #7 Test Program" << endl;
        Stack<char> Char10;         // Test Character Stack, Default constructor
        Stack<float> Float5 (5);     // Test Float Stack
        Stack<double> Double8(8);   // Test Double Stack
        Stack<bool> Bool2(2);       // Test Bool Stack
        Stack<char> Charcy(Char10); // Default copy constructor
        Bool2.Push(true);           // Test Push on Bool
        Bool2.Push(false);          // Test Push on Bool
        Bool2.Push(true);           // Test error on Push
        cout << "Size of Bool2 is:        "<< Bool2.Size()<<endl;
        cout << "Top element of Bool2 is: " << Bool2.Top() <<endl;
        cout << "Size on Double8 should be 8: "<< Double8.Size()<<endl;
        Char10.Push('A');
        Char10.Push('B');
        Char10.Push('C');
        cout << "Test Pop on Char10, should produce a 'C': ";
        Char10.Pop();
        Char10.Push('C');
        cout << "Test ostream overload on Charcy, should be Empty:  ";
        cout << Charcy<<endl;
        cout << "Test ostream overload on Char10, should be a 'C': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be a 'B': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be a 'A': ";
        cout <<Char10<< endl;
        cout << "Test ostream overload on Char10, should be an error: ";
        cout <<Char10<< endl;

        return 0;
    }


// ***************************************************************************************
// * Function Name: Overloading Operator friend Function (Char)						     *
// * Description: The overloading operator checks if there was an overloading, if its    *
// *   the case it returns an error message. Else it works as the copy constructor       *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


ostream &operator<<(ostream &os, Stack<char> &s)
{
    char item;
    if(!s.Empty())
    {
        item = s._stack[--s._top];
        cout << item;
    } else
        cout << "Empty Stack";

    return os;
}



// ***************************************************************************************
// * Function Name: Overloading Operator friend Function (float)			     	     *
// * Description: The overloading operator checks if there was an overloading, if its    *
// *   the case it returns an error message. Else it works as the copy constructor       *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


ostream &operator<<(ostream &os, Stack<float> &s)
{
    float item;
    if(!s.Empty())
    {
        item = s._stack[--s._top];
        cout << item;
    } else
        cout << "Empty Stack";

    return os;
}


// ***************************************************************************************
// * Function Name: Overloading Operator friend Function (double)						 *
// * Description: The overloading operator checks if there was an overloading, if its    *
// *   the case it returns an error message. Else it works as the copy constructor       *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


ostream &operator<<(ostream &os, Stack<double> &s)
{
    double item;
    if(!s.Empty())
    {
        item = s._stack[--s._top];
        cout << item;
    } else
        cout << "Empty Stack";

    return os;
}


// ***************************************************************************************
// * Function Name: Overloading Operator friend Function (bool)						     *
// * Description: The overloading operator checks if there was an overloading, if its    *
// *   the case it returns an error message. Else it works as the copy constructor       *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 06/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************

ostream &operator<<(ostream &os, Stack<bool> &s)
{
    bool item;
    if(!s.Empty())
    {
        item = s._stack[--s._top];
        cout << item;
    } else
        cout << "Empty Stack";

    return os;
}
