
#ifndef UNTITLED2_LIST_HPP
#define UNTITLED2_LIST_HPP

      // **************************************************************************
      // Name: Luciano Zavala                                                     *
      // Canvas User Name: lez17b                                                 *
      // Course: COP4530                                                          *
      // Instructor: Dr. David Gaitros                                            *
      // Assignment 4: This program is designed to create a doubly linklist       *
      //   based on subclass iterator and  const_iterator and all the methods     *
      //   that are related to the manipulation of the linklist and the           *
      //    complete data structure.                                              *
      // **************************************************************************


             //**************************************************************
             //**              C O N S T _ I T E R A T O R                 **
             //**************************************************************


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that creates a new constant iterator.              *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code for this constructor come from Dr. Gaitros's Web Conferences.      *
// ***************************************************************************************


template <class T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}


// ***************************************************************************************
// * Function Name: Protected Constructor						                         *
// * Description: Default constructor that creates a new constant iterator.              *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: code for this constructor come from Dr. Gaitros's Web Conferences.      *
// ***************************************************************************************


template <class T>
List<T>::const_iterator::const_iterator(Node * p)
{
    current = p;
}


// ***************************************************************************************
// * Function Name: Protected Retrieve Method  						                     *
// * Description: Retrieves the data from the Iterator                                   *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences.     *
// ***************************************************************************************


template <class T>
T & List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}


// ***************************************************************************************
// * Function Name:  Pointer Operator Method  						                     *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
const T & List<T>::const_iterator::operator*() const
{
    return retrieve();
}


// ***************************************************************************************
// * Function Name:  pre-increment operator Method  						             *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: Increments an Element using the operator		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()
{
    //next element to current
    current = current->next;
    return *this;
}


// ***************************************************************************************
// * Function Name:  post-increment operator Method  						             *
// * Description: Adds  data to the list                                                 *
// * Parameter Description: Increments an Element using the operator		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
    const_iterator old = *this;
    //moves one spot
    ++(*this);
    return old;
}

// ***************************************************************************************
// * Function Name:  pre-decrement operator Method  						             *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: Increments an Element using the operator		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()
{
    //current becomes the previous element
    current = current->prev;
    return *this;
}


// ***************************************************************************************
// * Function Name:  pre-decrement operator Method  						             *
// * Description: Decrements data from the list.                                         *
// * Parameter Description: Decrements an Integer using the operator		             *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
    const_iterator old = *this;
    // move one spot
    --(*this);
    return old;
}


// ***************************************************************************************
// * Function Name:  Equality operator Method  				         		             *
// * Description: Returns true if two lists are equal.                                   *
// * Parameter Description: List to evaluate.                        		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
    //Evaluates for equality
    return(current == rhs.current);
}


// ***************************************************************************************
// * Function Name:  Equality operator Method  				         		             *
// * Description: Returns true if two lists are equal.                                   *
// * Parameter Description: List to evaluate.                        		             *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book pg 97.              					                             *
// ***************************************************************************************


template <class T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
    //Evaluates for inequality
    return !(*this == rhs);
}


       //***********************************************************************
       //**                       I T E R A T O R                             **
       //***********************************************************************


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that creates an new Iterator.                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code for this constructor come from Dr. Gaitros's Web Conferences.      *
// ***************************************************************************************


template <class T>
List<T>::iterator::iterator()
{
    //Initializes the list
    init();
}


template <class T>
List<T>::iterator::iterator(Node * p): List<T>::const_iterator::const_iterator(p)
{}


// ***************************************************************************************
// * Function Name:  Pointer Operator Method  						                     *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
T & List<T>::iterator::operator*()
{
    //Retrieves the data
    return(const_iterator::retrieve());
}


// ***************************************************************************************
// * Function Name: Constant Pointer Operator Method  						             *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 01/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
const T & List<T>::iterator::operator*() const
{
    return(const_iterator::operator*());
}


// ***************************************************************************************
// * Function Name:  post-increment operator Method  						             *
// * Description: Adds data to the list                                                  *
// * Parameter Description: Increments an Element using the operator.		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book pg 97.        					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    // increment overload
    this->current = this->current->next;
    return *this;
}


// ***************************************************************************************
// * Function Name:  post-increment operator Method  						             *
// * Description: Adds data to the list                                                  *
// * Parameter Description: Increments an Element using the operator.		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book pg 97.        					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    // increment overload
    iterator old = *this;
    ++(*this);
    return old;
}


// ***************************************************************************************
// * Function Name:  pre-decrement operator Method  						             *
// * Description: Retrieves the data from the list                                       *
// * Parameter Description: Increments an Element using the operator		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::iterator & List<T>::iterator::operator--()
{
    // decrement overload
    this->current = this->current->prev;
    return(*this);
}


// ***************************************************************************************
// * Function Name:  pre-decrement operator Method  						             *
// * Description: Decrements data from the list.                                         *
// * Parameter Description: Decrements an Integer using the operator		             *
// * Date: 01/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Code  for this constructor come from Dr. Gaitros's Web Conferences and  *
// *   from the book.              					                                     *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    // decrement overload
    iterator old = *this;
    --(*this);
    return old;
}


            //*****************************************************************
            //**                         L I S T                             **
            //*****************************************************************


// ***************************************************************************************
// * Function Name: Initialization Method			     	                             *
// * Description: Method that creates an empty linklist.                                 *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
void List<T>::init()
{

    theSize = 0;
    head = new List::Node;
    tail = new List::Node;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that creates an empty linklist.                    *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
List<T>::List()
{
    //Initializes the list
    init();
}


// ***************************************************************************************
// * Function Name: Destructor				             		                         *
// * Description: Loops through the list and deletes everything.                         *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
List<T>::~List()
{
    //Clears the content
    clear();
    delete head;
    delete tail;
}


// ***************************************************************************************
// * Function Name: Copy Constructor				             		                 *
// * Description: Copies everything form a list to another.                              *
// * Parameter Description: It has a List as Parameter.        			                 *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. This code comes from the book pg 98.                    *
// ***************************************************************************************


template <class T>
List<T>::List(const List &rhs)
{
    init();
    //Populates the list
    for (auto & x: rhs)
        push_back(x);

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


template <class T>
List<T>::List(List && rhs)
{
    //Moves the content from one side to the other
    theSize = rhs.theSize;
    head = rhs.head;
    tail = rhs.tail;
    rhs.theSize = 0;

    //Ses head and tail to null
    rhs.head = nullptr;
    rhs.tail = nullptr;
}


// ***************************************************************************************
// * Function Name: Parameter Constructor						                         *
// * Description: Constructor that uses the parameters to define the size and the values *
// *   that will be inside the list.                                                     *
// * Parameter Description: val for values and num for the number of items.              *
// * Date: 03/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Also my previous code.                                  *
// ***************************************************************************************


template <class T>
List<T>::List(int num, const T& val)
{
    init();
    for(int i = 0; i < num; i++)
    {
        // loop through list adding val
        push_back(val);
    }
}


// ***************************************************************************************
// * Function Name: Parameter Constructor						                         *
// * Description: Constructor that uses the parameters to define the size and the values *
// *   that will be inside the list.                                                     *
// * Parameter Description: val for values and num for the number of items.              *
// * Date: 03/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Also my previous code.                                  *
// ***************************************************************************************


template <class T>
List<T>::List(const_iterator start, const_iterator end)
{
    init();
    //Iterator
    auto iterator = start;

    //Loops to populate
    while(iterator !=  end)
    {
        push_back(*iterator);
        iterator++;
    }
}


// ***************************************************************************************
// * Function Name: Parameter Constructor						                         *
// * Description: Constructor that uses the parameters to define the size and the values *
// *   that will be inside the list.                                                     *
// * Parameter Description: val for values and num for the number of items.              *
// * Date: 03/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Also my previous code.                                  *
// ***************************************************************************************


template <class T>
List<T>::List(std::initializer_list<T> iList)
{
    init();

    //Loops to populate
    for(T i : iList)
        push_back(i);
}


// ***************************************************************************************
// * Function Name: Copy assignment operator.       				                     *
// * Description: Copies all data to corresponding variables using the = operator.       *
// * Parameter Description: It has a Tlist as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
const List<T>& List<T>::operator=(const List &rhs)
{
    //Clears content
    clear();
    auto iterator = rhs.begin();

    //Loops to copy the content
    for(int i = 0; i < rhs.size(); i++)
    {
        push_back(iterator.retrieve());
        iterator++;
    }

    return *this;
}


// ***************************************************************************************
// * Function Name: Move assignment operator.       				                     *
// * Description: Copies all data to corresponding variables using the = operator.       *
// * Parameter Description: It has a list as Parameter.        			                 *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
List<T> & List<T>::operator=(List && rhs)
{
    //Moves the node pointers
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);

    return *this;
}


// ***************************************************************************************
// * Function Name: Move assignment operator with initializer list.                      *
// * Description: Copies all data to corresponding variables using the = operator.       *
// * Parameter Description: It has a list as Parameter.        			                 *
// * Date: 04/02/2021  									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code also from the book pg 98.                          *
// ***************************************************************************************


template <class T>
List<T>& List<T>::operator=(std::initializer_list<T> iList)
{
    init();

    //Loops to populate
    for(T i : iList)
        push_back(i);
}


// ***************************************************************************************
// * Function Name: Size Function                				                         *
// * Description: Returns the size of the list.                                          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
int List<T>::size() const
{
    // return size
    return theSize;
}


// ***************************************************************************************
// * Function Name: Empty Function                		    		                     *
// * Description: Returns true if the list is empty.                                     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
bool List<T>::empty() const
{
    // return false if list great than 0, true otherwise
    if(theSize == 0)
        return true;
    else
        return false;
}


// ***************************************************************************************
// * Function Name: Clear Function                   				                     *
// * Description: Clears the contents of the list.                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::clear()
{
    // clear list
    auto iterator = begin();

    //loops until iterator reaches the tail
    while(iterator.current != tail)
    {
        iterator = erase(iterator);
    }
}


// ***************************************************************************************
// * Function Name: Reverse Function                   				                     *
// * Description: reverses the contents of the list.                                     *
// * Parameter Description: This function has no parameters.	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::reverse()
{
    // reverse list
    auto iterator = end();
    List<T> reversedList;
    iterator--;

    for(int i = 0; i < theSize; i++)
    {
        reversedList.push_back(*iterator);
        iterator--;
    }

    // reassign pointer
    *this = reversedList;
}


// ***************************************************************************************
// * Function Name: Front Function                   				                     *
// * Description: Return the contents of the front element on the list.                  *
// * Parameter Description: This function has no parameters.	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
T& List<T>::front()
{
    // point to first item
    return head->next->data;
}


// ***************************************************************************************
// * Function Name: Constant Front Function                      	                     *
// * Description: Return the contents of the front element on the list.                  *
// * Parameter Description: This function has no parameters.	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
const T& List<T>::front() const
{
    // point to first item
    return head->next->data;
}


// ***************************************************************************************
// * Function Name: Back Function                   				                     *
// * Description: Return the contents of the Bakc element on the list.                   *
// * Parameter Description: This function has no parameters.	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
T& List<T>::back()
{
    // point to last item
    return tail->prev->data;
}


// ***************************************************************************************
// * Function Name: Constant Back Function                   				             *
// * Description: Return the contents of the Bakc element on the list.                   *
// * Parameter Description: This function has no parameters.	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
const T& List<T>::back() const
{
    // point to last item
    return tail->prev->data;
}


// ***************************************************************************************
// * Function Name: push_front Function                       				             *
// * Description: Inserts an element at the beginning of the list.                       *
// * Parameter Description: constant value                   	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::push_front(const T & val)
{
    // push to front of list
    insert(begin(), val);
}


// ***************************************************************************************
// * Function Name: push_front Function                       				             *
// * Description: Inserts an element at the beginning of the list.                       *
// * Parameter Description: value                           	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::push_front(T && val)
{
    // push to front of list
    insert(begin(), std::move(val));
}


// ***************************************************************************************
// * Function Name: push_back Function                       				             *
// * Description: Inserts an element at the beginning of the list.                       *
// * Parameter Description: constant value                   	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::push_back(const T & val)
{
    // push to end of list
    insert(end(), val);
}


// ***************************************************************************************
// * Function Name: push_back Function                       				             *
// * Description: Inserts an element at the beginning of the list.                       *
// * Parameter Description: value                   	   			                     *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::push_back(T && val)
{
    // push to end of list
    insert(end(), std::move(val));
}


// ***************************************************************************************
// * Function Name: pop_front Function                       				             *
// * Description: Removes an element at the beginning of the list.                       *
// * Parameter Description: value                           	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::pop_front()
{
    // remove first
    erase(begin());
}


// ***************************************************************************************
// * Function Name: pop_front Function                       				             *
// * Description: Removes an element at the beginning of the list.                       *
// * Parameter Description: value                           	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::pop_back()
{
    // remove last
    erase(end().current->prev);
}


// ***************************************************************************************
// * Function Name: remove Function                          				             *
// * Description: Removes an element of the list.                                        *
// * Parameter Description: value                           	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
void List<T>::remove(const T &val)
{
    // remove val
    auto itr = begin();

    do{
        if(itr.retrieve() == val)
            itr = erase(itr);
        else
            ++itr;
    }while(itr != end());
}


// ***************************************************************************************
// * Function Name: remove_if Function                          				         *
// * Description: Removes an element of the list based on a condition.                   *
// * Parameter Description: value                           	   			             *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)
{
    // remove all elements for which Predicate pred
    auto itr = begin();

    // Iterates until it finds the data element
    while(itr != end())
    {
        if(pred(*itr) == true)
            itr = erase(itr);
        else
            ++itr;
    }
}


// ***************************************************************************************
// * Function Name: Print Function                       	    	                     *
// * Description: This function is designed to print every element on the list.          *
// * Parameter Description: Ostream parameter and a char delimiting 			         *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


template <class T>
void List<T>::print(std::ostream& os, char ofc) const
{
    // print
    const_iterator itr = begin();

    // Prints the content
    for(int i = 0; i < theSize - 1; i++)
    {
        os << itr.retrieve() << ofc;
        itr++;
    }
    os << itr.retrieve();
}


// ***************************************************************************************
// * Function Name: begin Function                          				             *
// * Description: Return the iterator to the beginning of the list.                      *
// * Parameter Description: No parameters                           	   			     *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::begin()
{
    // front of list
    return {head->next};
}


// ***************************************************************************************
// * Function Name: begin Function Constant                         				     *
// * Description: Return the iterator to the beginning of the list.                      *
// * Parameter Description: No parameters                           	   			     *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator List<T>::begin() const
{
    // const front of list
    return {head->next};
}


// ***************************************************************************************
// * Function Name: End Function                             				             *
// * Description: Return the iterator to the end of the list.                            *
// * Parameter Description: No parameters                           	   			     *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::end()
{
    // end of list
    return {tail};
}


// ***************************************************************************************
// * Function Name: End Function Constant                         			             *
// * Description: Return the iterator to the end of the list.                            *
// * Parameter Description: No parameters                           	   			     *
// * Date: 02/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code from the book pg. 98.                              *
// ***************************************************************************************


template <class T>
typename List<T>::const_iterator List<T>::end() const
{
    // const end of list
    return {tail};
}


// ***************************************************************************************
// * Function Name: Insert Function              				                         *
// * Description: Inserts a value at the beginning of the list and increases the size    *
// *   by one.                                                                           *
// * Parameter Description: itr as the iterator and constant val the value assigned.     *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val)
{
    // insert
    Node *p = itr.current;
    ++theSize;
    return {p->prev = p->prev->next = new Node{val, p->prev, p}};
}


// ***************************************************************************************
// * Function Name: Insert Function              				                         *
// * Description: Inserts a value at the beginning of the list and increases the size    *
// *   by one.                                                                           *
// * Parameter Description: itr as the iterator and constant val the value assigned.     *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)
{
    Node *p = itr.current;
    ++theSize;

    // Returns a new node pointing to the inserting location
    return { p->prev = p->prev->next = new Node{ std::move(val), p->prev, p}};
}


// ***************************************************************************************
// * Function Name: Erase Function              				                         *
// * Description: Deletes an element of the list at the iteration position.              *
// * Parameter Description: itr as the iterator and constant val the value assigned.     *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
    // remove
    List<T>::Node * p = itr.current;

    // sourced from lecture slides
    List<T>::iterator retVal { p->next };
    p->prev->next = p->next;
    p->next->prev = p->prev;

    //deletes de file
    delete p;
    -- theSize;
    return retVal;
}


// ***************************************************************************************
// * Function Name: Erase Function              				                         *
// * Description: Deletes an element of the list at the iteration position.              *
// * Parameter Description: Iterates from te start to the end.                           *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <class T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
    // loop through and remove all
    iterator itr = start;

    //Loops to erase with the size method
    for(int i = 0; i < theSize - 1; i++)
        itr = erase(itr);

    return end;
}


// ***************************************************************************************
// * Function Name: Comparison Overloading Function.               			             *
// * Description: Returns true if the two lists are equal.                               *
// * Parameter Description: Two lists.                                                   *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <typename T>
bool operator==(const List<T> &lhs, const List<T> &rhs)
{
    // == overload
    auto itrlhs = lhs.begin();
    auto itrrhs = rhs.begin();

    if(lhs.size() != rhs.size())
        return false;

    while(itrlhs != lhs.end())
    {
        if(*itrlhs != *itrrhs)
            // iterate through list checking each one..
            return false;
        ++itrlhs;
        ++itrrhs;
    }

    return true;
}


// ***************************************************************************************
// * Function Name: Comparison Inequality Overloading Function.               		     *
// * Description: Returns true if the two lists are not equal.                           *
// * Parameter Description:  two lists.                                                  *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************


template <typename T>
bool operator!=(const List<T> &lhs, const List<T> &rhs)
{
    // opposite of == operation
    return !(lhs == rhs);
}


// ***************************************************************************************
// * Function Name: Output Overloading Function.               		                     *
// * Description: Prints the content and given by the list os and the ostream.           *
// * Parameter Description:  two lists.                                                  *
// * Date: 05/02/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given. Code form the book pg 100.                              *
// ***************************************************************************************

template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
    // output overload
    l.print(os);
}


#endif //UNTITLED2_LIST_HPP
