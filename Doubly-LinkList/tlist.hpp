#ifndef UNTITLED27_TLIST_HPP
#define UNTITLED27_TLIST_HPP

// **************************************************************************
// Name: Luciano Zavala                                                     *
// Canvas User Name: lez17b                                                 *
// Course: COP4530                                                          *
// Instructor: Dr. David Gaitros                                            *
// Assignment 4: This program is designed to create a doubly linklist       *
//   based on iterators and all the methods that are related to the         *
//   manipulation of the linklist and the complete data structure.          *
// **************************************************************************

#include <iostream>
#include <iterator>

// ********************************************************************
// * Name: TList Implementation Class                                 *
// * Description: A template tList class implementation designed      *
// * to be used with any simple C++ type to include floating point,   *
// * double, floating point, character, and string.                   *
// * Author: Luciano Zavala                                           *
// * Date: January 17, 2021                                           *
// ********************************************************************

using namespace std;

// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that creates an empty linkedlist.                  *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TList<T>::TList()
{
    //creates an empty linked list
    first = nullptr;
    last = nullptr;
    size = 0;
}

// ***************************************************************************************
// * Function Name: Parameter Constructor						                         *
// * Description: Constructor that uses the parameters to define the size and the values *
// *   that will be inside the list.                                                     *
// * Parameter Description: val for values and num for the number of items.              *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TList<T>::TList(T val, int num)
{
    //creates an empty linked list
    first = nullptr;
    last = nullptr;
    size = 0;

    //Loops to populate the List
    for(int i = 1; i <= num; i++)
    {
        InsertFront(val);
    }
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

template<typename T>
TList<T>::~TList<T>()
{
    //Iterator Variable
    auto iter = GetIterator();

    // loop through the list and delete backwards
    for(int i = 1; i < size; i++)
    {
        iter.Next();
        delete iter.ptr->prev;
        if(i == size)
        {
            // deletes the final node
            delete iter.ptr;
        }
    }

}

// ***************************************************************************************
// * Function Name: Copy Constructor				             		                 *
// * Description: Copies everything form a list to another.                              *
// * Parameter Description: It has a Tlist as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
TList<T>::TList(const TList& L)
{
    //Iterator Variable
    auto iterator = L.GetIterator();

    //Constructs an empty list
    first = nullptr;
    last = nullptr;
    size = 0;

    //Iterates through the list and inserts elements in the back
    for(int i = 0; i < L.GetSize(); i++)
    {
        InsertBack(iterator.GetData());
        iterator.Next();
    }
}

// ***************************************************************************************
// * Function Name: Copy Assignment Operator.				      		                 *
// * Description: Copies everything form a list to another using the = operator.         *
// * Parameter Description: It has a Tlist as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
TList<T> & TList<T>::operator=(const TList& L)
{
    // clear the list before copying
    Clear();
    auto iterator = L.GetIterator();

    // loop through whole list iterating through and inserting at back
    for(int i = 0; i < L.GetSize(); i++)
    {
        InsertBack(iterator.GetData());
        iterator.Next();
    }
    return *this;
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
TList<T>::TList(TList && L)
 {
    // Copies all the data to the corresponding variables
    size = L.size;
    first = L.first;
    last = L.last;
}

// ***************************************************************************************
// * Function Name: Move assignment operator.       				                     *
// * Description: Copies all data to corresponding variables using the = operator.       *
// * Parameter Description: It has a Tlist as Parameter.        			             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<class T>
TList<T> TList<T>::operator=(TList && L)
 {
    int value = 0;
    Node<T> *NodePtr = first;

    // move value of L.first
    first = L.first;
    // switch the pointers for the first variable
    L.first = NodePtr;
    // switch the pointers  for  the last variable
    NodePtr = last;
    last = L.last;
    L.last = NodePtr;
    // copies the list sizes to value variable
    value = size;
    size = L.size;
    L.size = value;

    return *this;
}

// ***************************************************************************************
// * Function Name: IsEmpty Function                				                     *
// * Description: Returns true if the list is empty.                                     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
bool TList<T>::IsEmpty() const
{
    //returns true if empty
    if(size == 0)
    {
        return true;
    }
    else
        return false;
}

// ***************************************************************************************
// * Function Name: GetSize Function                				                     *
// * Description: Returns the size of the list.                                          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
int TList<T>::GetSize() const
{
    return size;
}

// ***************************************************************************************
// * Function Name: InsertFront Function              				                     *
// * Description: Inserts a value a the beginning of the list and increse the size       *
// *   by one.                                                                           *
// * Parameter Description: d of Type T variable that is going to be inserted.	         *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
void TList<T>::InsertFront(const T &d)
{
    // node variable
    auto *node = new Node<T>(d);

    //If empty, assigns the node to the first.
    if(size == 0)
    {
        first = node;
        last = node;
        size++;
    }
    else
    {
        // Moves the first to the next node
        node->next = first;
        // Return the node to the previous
        first->prev = node;
        // Assigns the element to the first place
        first = node;
        // Increases size
        size++;
    }
}

// ***************************************************************************************
// * Function Name: InsertBack Function              				                     *
// * Description: Inserts a value a the back of the list and increases the size          *
// *   by one.                                                                           *
// * Parameter Description: d of Type T variable that is going to be inserted.	         *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
void TList<T>::InsertBack(const T &d)
{
    // node variable
    auto *node = new Node<T>(d);

    //If empty, assigns the node to the first.
    if(size == 0)
    {
        first = node;
        last = node;
        size++;
    }
    else
    {
        // Moves the last to the previous node
        node->prev = last;
        // Return the node to the next one
        last->next = node;
        // Assigns the element to the last place
        last = node;
        // Increases size
        size++;
    }
}

// ***************************************************************************************
// * Function Name: RemoveFront Function              				                     *
// * Description: Removes the element in the front place of the list.                    *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
void TList<T>::RemoveFront()
{

    // if size == 1 we can just delete it and reset its values
    if(size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
        // set default values
        size = 0;
    }
    // if size > 1 we have to shift pointers around and remove item
    if(size > 1)
    {
        Node<T> *NodePtr = first->next;
        NodePtr->prev = 0;
        delete first;
        // reset the pointers new value
        first = NodePtr;
        // decrement the size of list
        size--;
    }
}

// ***************************************************************************************
// * Function Name: RemoveBack Function              				                     *
// * Description: Removes the element in the last place of the list.                     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
void TList<T>::RemoveBack()
{
    // if size of list == 1 we can just delete it and reset its values
    if(size == 1)
    {
        delete last;
        first = nullptr;
        last = nullptr;
        // set default (empty list) values
        size = 0;
    }
    // if size of list > 1 we have to shift pointers around and remove item
    if(size > 1)
    {
        Node<T> *NodePtr = last->prev;
        NodePtr->next = 0;
        delete last;
        // reset Pointers new value
        last = NodePtr;
        // decrement the size of list
        size--;
    }
}

// ***************************************************************************************
// * Function Name: Clear Function                   				                     *
// * Description: Clears the contents of the list.                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
void TList<T>::Clear()
{
    //Loop to remove every front element of the list
    for(int i = 0; i < size; i++)
    {
        RemoveFront();
    }
    // Sets the list all to empty
    first = nullptr;
    last = nullptr;
    size = 0;
}

// ***************************************************************************************
// * Function Name: getFirst Function                   	    	                     *
// * Description: gets the first element of the list                                     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
T& TList<T>::GetFirst() const
{
    // returns the first element
    return first->data;
}

// ***************************************************************************************
// * Function Name: getLast Function                    	    	                     *
// * Description: gets the last element of the list                                      *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
T& TList<T>::GetLast() const
{
    // returns the last element
    return last->data;
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
void TList<T>::Print(std::ostream& os, char delim) const
{
    //iterator variable
    auto iterator = this->GetIterator();

    // Loops in order to print each element
    for(int i = 0; i < size; i++)
    {
        os << iterator.GetData() << delim;
        iterator.Next();
    }
}

// ***************************************************************************************
// * Function Name: GetIterator Function                       	    	                 *
// * Description: This function is designed to Return an iterator object created using   *
// *   the friend class. It is referred to the first variable iterator.                  *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TListIterator<T> TList<T>::GetIterator() const
{
    TListIterator<T> Iterator;

    // Assigns the first value to the pointer iterator
    Iterator.ptr = first;
    return Iterator;
}

// ***************************************************************************************
// * Function Name: GetIteratorEnd Function                       	    	             *
// * Description: This function is designed to Return an iterator object created using   *
// *   the friend class. It is referred to the last variable iterator.                   *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
TListIterator<T> TList<T>::GetIteratorEnd() const
{
    TListIterator<T> iterator;

    // Assigns the last value to the pointer iterator
    iterator.ptr = last;
    return iterator;
}

// ***************************************************************************************
// * Function Name: Insert Function                             	    	             *
// * Description: This function is designed to insert an element at the position give    *
// *   and the value assigned to it.                                                     *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
void TList<T>::Insert(TListIterator<T> pos, const T& d)
{
    // Node Variable
    Node<T> *pNode;
    // temporary node variable
    auto *temporaryNode = new Node<T>(d);

    // if there is a previous node, copy its contents to pNode
    if(pos.HasPrevious())
    {
        pNode = pos.ptr->prev;
    }
    else{
        pNode = nullptr;
    }
    // switch the pointers
    temporaryNode->next = pos.ptr;
    pos.ptr->prev = temporaryNode;

    // if this is first of list, set properly
    if(pNode == nullptr)
    {
        first = temporaryNode;
    }
    else
    {
        pNode->next = temporaryNode;
        temporaryNode->prev = pNode;
    }
    // Increases size
    size++;
}

// ***************************************************************************************
// * Function Name: Remove Function                             	    	             *
// * Description: This function is designed to remove an element at the position given.  *
// * Parameter Description: This function has the position parameter.				     *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template <class T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos)
{
    // Current node variable
    Node<T> *currentNode = pos.ptr;
    // Previous node variable
    Node<T> *prevNode = currentNode->prev;
    // next node variable
    Node<T> *nextNode = currentNode->next;

    // iterate to next and swap the pointers so it can be returned
    pos.Next();
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    // current can is deleted
    delete currentNode;

    // Size decreases by one
    size--;

    return pos;
}


//***************************************************************************************************************
//*                                                                                                            **
//*                                   TListIterator Class Implementation                                       **
//*                                                                                                            **
//***************************************************************************************************************


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that creates an empty TListIterator.               *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TListIterator<T>::TListIterator()
{
    ptr = nullptr;
}

// ***************************************************************************************
// * Function Name: HasNext function		     			                             *
// * Description: The function is designed to return true if theres a value in the next  *
// *    value.                                                                           *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
bool TListIterator<T>::HasNext() const
{
    if(ptr->next == nullptr)
    {
        return false;
    }
    else
        return true;
}

// ***************************************************************************************
// * Function Name: HasPrevious function		     			                         *
// * Description: The function is designed to return true if there's a value in the prev *
// *    value.                                                                           *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
bool TListIterator<T>::HasPrevious() const
{
    if(ptr->prev == nullptr)
    {
        return false;
    }
    else
        return true;
}

// ***************************************************************************************
// * Function Name: Next function		     			                                 *
// * Description: The function is designed to return the next value to iterate,          *
// *   if there's no next values returns the last one.                                   *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TListIterator<T> TListIterator<T>::Next()
{
    if(HasNext())
        ptr = ptr->next;

    return *this;
}

// ***************************************************************************************
// * Function Name: Previous function		     			                             *
// * Description: The function is designed to return the previous value to iterate,      *
// *   if there's no previous values returns the last one.                               *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
TListIterator<T> TListIterator<T>::Previous()
{
    if(HasPrevious())
        ptr = ptr->prev;

    return *this;
}

// ***************************************************************************************
// * Function Name: GetData function		     			                             *
// * Description: The function is designed to return data assigned to the pointer.       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************

template<typename T>
T& TListIterator<T>::GetData() const
{
    return ptr->data;
}


#endif //UNTITLED27_TLIST_HPP
