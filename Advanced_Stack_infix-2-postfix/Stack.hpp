
#ifndef UNTITLED103_STACK_HPP
#define UNTITLED103_STACK_HPP

// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that assigns a default size of 100 to the Stack,	 *
// *   asignes the top value to 0 and creates the stack of type T.                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previos Stack code            					                     *
// ***************************************************************************************


template <typename T>
Stack<T>::Stack()
{}


// ***************************************************************************************
// * Function Name: Destructor				             		                         *
// * Description: Deletes everything frm the stack.                                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <typename T>
Stack<T>::~Stack()
{
    //Clears the vector
    v.clear();
}


// ***************************************************************************************
// * Function Name: Copy Constructor						                             *
// * Description: the copy constructor has the duty of copying all the values in a stack *
// *   to another, asigning the type of the stack T.                                     *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 16/02/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


template <typename T>
Stack<T>::Stack(const Stack<T> & x)
{
    *this = x;
}


// ***************************************************************************************
// * Function Name: Move Constructor         				      		                 *
// * Description: Copies all data to corresponding variables.                            *
// * Parameter Description: It has a Tlist as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <typename T>
Stack<T>::Stack(Stack<T> && x)
{
    *this = x;
}


// ***************************************************************************************
// * Function Name: Copy Assignment Operator        				                     *
// * Description: Copies all data to corresponding variables.                            *
// * Parameter Description: It has a Stack as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & b)
{
    v = b.v;
    return *this;
}


// ***************************************************************************************
// * Function Name: Print            						                             *
// * Description: Prints the Stack content.                                              *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
void Stack<T>::print(std::ostream & os, char ofc) const
{
    for(auto itr = v.begin(); itr != v.end(); ++itr)
    {
        os << *itr << ofc;
    }
}

// ***************************************************************************************
// * Function Name: Move Assignment Operator        				                     *
// * Description: Copies all data to corresponding variables.                            *
// * Parameter Description: It has a Stack as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && b)
{
    v = b.v;
    return *this;
}


// ***************************************************************************************
// * Function Name: Empty            						                             *
// * Description: Returns true if the stack is empty, false if not.                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
bool Stack<T>::empty() const
{
    return v.empty();
}


// ***************************************************************************************
// * Function Name: Clear Function                   				                     *
// * Description: Clears the contents of the Stack.                                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <typename T>
void Stack<T>::clear()
{
    v.clear();
}


// ***************************************************************************************
// * Function Name: Push            						                             *
// * Description: This function adds an element to the end of the stack, asigning new    *
// *   size, and top value.                                                              *
// * Parameter Description: The parameters on this function refer to the item to attach  *
// * Date: 11/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
void Stack<T>::push(const T& x)
{
    v.push_back(x);
}


// ***************************************************************************************
// * Function Name: Push            						                             *
// * Description: This function adds an element to the end of the stack, asigning new    *
// *   size, and top value.                                                              *
// * Parameter Description: The parameters on this function refer to the item to attach  *
// * Date: 11/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
void Stack<T>::push(T&& x)
{
    v.push_back(x);
}


// ***************************************************************************************
// * Function Name: Pop               						                             *
// * Description: This function removes an element to the end of the stack, asigning new *
// *   size, and top value.                                                              *
// * Parameter Description: The parameters on this function.				             *
// * Date: 12/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
void Stack<T>::pop()
{
    v.pop_back();
}


// ***************************************************************************************
// * Function Name: Top            						                                 *
// * Description: This function return the top element assigned for each stack.          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/02/2021				     				                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
T& Stack<T>::top()
{
    return v.back();
}


// ***************************************************************************************
// * Function Name: Top            						                                 *
// * Description: This function return the top element assigned for each stack.          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/02/2021				     				                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.          					                     *
// ***************************************************************************************


template <typename T>
const T& Stack<T>::top() const
{
    return v.back();
}


// ***************************************************************************************
// * Function Name: Size            						                             *
// * Description: Returns the size of the stack.                                         *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
int Stack<T>::size() const
{
    return v.size();
}


// ***************************************************************************************
// * Function Name: Assignment operator that calls for the Print() function.             *
// * Description: Prints the Stack content.                                              *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
std::ostream & operator << (std::ostream & os, const Stack<T> & a)
{
    a.print(os);
    return os;
}


// ***************************************************************************************
// * Function Name: Comparison Operator            			                             *
// * Description:  Compares two stacks and returns true if both are equal.               *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
bool operator == (const Stack<T> & a, const Stack<T> & b)
{
    return a.getVector() == b.getVector();
}


// ***************************************************************************************
// * Function Name: Comparison (inequality) Operator     	                             *
// * Description:  Compares two stacks and returns true if both are unequal.             *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
bool operator != (const Stack<T> & a, const Stack<T> & b){ // opposite of operator==()
    return !(a == b);
}


// ***************************************************************************************
// * Function Name: Comparison (Bigger than) Operator     	                             *
// * Description:  Compares two stacks and returns true if there are smaller values.     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 15/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
bool operator <= (const Stack<T> & a, const Stack<T> & b)
{
    return a.getVector() <= b.getVector();
}


// ***************************************************************************************
// * Function Name: getVector function                  	                             *
// * Description:  Returns the contents on the vectors.                                  *
// * Parameter Description: This function has no parameters.				             *
// * Date: 15/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


template <typename T>
std::vector<T> Stack<T>::getVector() const
{
    return v;
}

#endif //UNTITLED103_STACK_HPP
