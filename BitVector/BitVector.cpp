//
// Created by Luciano Zavala on 5/25/20.
//
// **************************************************************************
// * Name: Luciano Zavala							                        *
// * Canvas User Name: lez17b						                        *
// * Course: COP3330- Object Oriented Programming			                *
// * Instructor: Dr. David Gaitros					                        *
// * Assignment 3: BitVector Program- This program will implement	        *
// *	a bitvector of sizes that are undetermined or determined. Also will	*
// *	allocate bits to the size of 32 bits per word	                    *
// *	and use constructors and operators to turn bits on and off.	        *
// **************************************************************************

#include <iostream>

#include "bitvector.h"

using namespace std;

//Constant Variable for default bits
const size_t DEFAULTBITS = 256;

// ***************************************************************************************
// * Function Name: BitVector Constructor						                         *
// * Description: Default constructor that holds a size of 256 bits, with a constant of  *
// * 	DEFAULTBITS that is intialized to 256, the word size is 256/32 	                 *
// * 	which is 8. It also unsets all the bits using the call to the Unset function	 *
// * Parameter Description: This function has no parameters.				             *
// * Date: 02/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Bit Vector Program.					                 *
// ***************************************************************************************


BitVector::BitVector()
{
    //Division to determine the size.
    size = (DEFAULTBITS / 32);

    bvect = new int [size];

    //Error message display
    if (bvect == 0)
    {
        cerr << "Error! Bit Vector is equal to 0!" << endl;
        exit (EXIT_FAILURE);
    }

    //Unset function to unset the bits used
    Unset();
}


// **************************************************************************************
// * Function Name: BitVector Constructor with an specified BitVector size			    *
// * Description: BitVector constructor, which explicit  name is in bitvector.h. It	    *
// * 	creates a BitVector Class with a specific  amount of bits  in the function.	    *
// *	It as well unsets all the bits using the Unset function.		                *
// * 	To determine the word size, we use the parameter and divide it by 32 bits, and 	*
// * 	allocate that total size of bits to the amount of words to the bitvector.	    *
// * Parameter Description: The parameter is the number of bits, which is the amount of	*
// *	bits that is divided by 32 (word size) and allocated to size. If	            *
// *	there is a remainder, then the word size increments and allocates one more word.*
// * Date: 21/02/2020									                                *
// * Author: Luciano Zavala. Information Technology Student at FSU				        *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	    *
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


BitVector::BitVector(size_t numberofbits)
{
    //Determine the size
    size = (numberofbits / 32);

    if (numberofbits % 32 != 0)
        size++;

    //Error message display
    if (numberofbits <= 0)
    {
        cerr << "Error! The number of bits is less than 0! Please enter bits greater than that value." << endl;
        exit(EXIT_FAILURE);
    }

    bvect = new int [size];

    //Unset function
    Unset();
}

// **************************************************************************************
// * Function Name: Set Function							                            *
// * Description: The function defines the location of the bit, and sets an		        *
// *	individual bit to on position. We use the same code like in the Test function, 	*
// *	but now we use the OR operation to make sure the mask corresponds with the word *
// *	to turn the bit on.								                                *
// * Parameter Description: The parameter for this function is the index parameter	    *
// * 	which we use to see to turn the individual bit.					                *
// * Date: 04/06/2020	                                								*
// * Author: MLuciano Zavala,  Information Technology Student at FSU 		     		*
// * References: Ideas for the Set function come from Dr. Gaitros's Web Conferences	    *
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Set(const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = index / 32;
    offset = index % 32;
    offset = 31 - offset;
    mask = mask << offset;

    bvect[word] = bvect[word] | mask;
}


// **************************************************************************************
// * Function Name: Set all bits Function							                    *
// * Description: This function makes every bit equal to -1, or "set", we do this    	*
// *	by allocating the bvector with the index which is less than the word size	    *
// *	and all words will be equal to -1, and set all the bits.					    *
// * Parameter Description: This function has no parameters.				            *
// * Date: 04/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU					    *
// * References: Ideas for the Set all function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Set()
{
    for (size_t index = 0; index < size; index++)
        bvect[index] = -1;
}


// **************************************************************************************
// * Function Name: Unset all the bits.							                        *
// * Description: This function makes ALL bits equal to 0, or "not set". This is done	*
// *	by allocating the bvector to the index, which is less than the size of the word	*
// *	and all words will be equal to zero. Finally it unset the bits.				    *
// * Parameter Description: This function has no parameters.				            *
// * Date: 03/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU					    *
// * References: Ideas for the Unset function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Unset()
{
    for (size_t index = 0; index < size; index++)
        bvect[index] = 0;
}


// ******************************************************************************************
// * Function Name: Unset one (index) bit						                            *
// * Description: The function finds the bit to be unset, and makes utilization of the Test	*
// *	function to see if the bit is turned on or not. If the bit is turned on, then	    *
// *	the Flip function is called and also unsets the bit.				                *
// * Parameter Description: The parameter for this function is the index, it is used	    *
// *	to see if the bit is turned on or not.                                           	*
// * Date: 03/06/2020									                                    *
// * Author: Luciano Zavala,  Information Technology Student at FSU							*
// * References: Ideas for the Unset all bits come from Dr. Gaitros's Web Conferences	    *
// * 	and Lecture Videos on the Bit Vector Program.					                    *
// ******************************************************************************************


void BitVector::Unset(const size_t index)
{
    if (Test(index))
        Flip(index);
}


// **************************************************************************************
// * Function Name: Flip Function							                            *
// * Description: This function determines the location of the bit, it also flips a		*
// *	bit to ON or OFF it. We use the same logic as  the Test function,	            *
// *	but now we use the XOR operation. 						                        *
// * Parameter Description: The parameter for this function is the index parameter	    *
// * 	which we use to see to turn the individual bit on or off.			            *
// * 	Also, it passes the value by a constant because we do not want to change the    *
// *    value.                                                                          *
// * Date: 21/02/2020									                                *
// * Author: Marco Jaen, CS at FSU							                            *
// * References: Ideas for the Flip function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Flip(const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = index / 32;
    offset = index % 32;
    offset = 31 - offset;
    mask = mask << offset;

    bvect[word] = bvect[word] ^ mask;
}


// **************************************************************************************
// * Function Name: Flips all bits Function							                    *
// * Description: This function flips all the bits if they are unset or set. We do	    *
// *	this by looping through every bit using the for statement, and 	                *
// *	calls the Flip all function for each specific bit.				                *
// * Parameter Description: This function has no parameters.			             	*
// * Date: 05/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU					    *
// * References: Ideas for the Flip all function come from Dr. Gaitros's Web Conferences*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Flip()
{
    for (size_t index = 0; index < size * 32; index++)
        Flip(index);
}


// **************************************************************************************
// * Function Name: Test function							                            *
// * Description: This function determines the location of the bit, also returns true	*
// * 	or false depending on the mask. We use a mask to manipulate the bit, by	        *
// *	dividing the index by 32, also finding the offset in order to find by how many	*
// *	shifts the mask should manipulate the bit.                                   	*
// * Parameter Description: The parameter of this function is the index parameter	    *
// * 	which we use to see if that individual indexed bit is turned on or not. 	    *
// * 	Also it is  passed  as a constant because we do not want to change the value.   *
// * Date: 04/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU					    *
// * References: Ideas for the Test function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


bool BitVector::Test(size_t index) const
{

    size_t word;
    size_t offset;
    size_t mask = 1;


    word = index / 32;
    offset = index % 32;
    offset = 31 - offset;
    mask = mask << offset;


    mask = bvect[word] & mask;
    if (mask != 0)
        return true;
    else
        return false;
}


// **************************************************************************************
// * Function Name: Print Function							                            *
// * Description: This function prints all the bits that are either not set or set.    	*
// *	A for loop is used to go through every individual bit and as well to call	    *
// *	the Test function to see if the indexed bit is turned on or not, also prints	*
// *	the result to the console.							                            *
// * Parameter Description: This function has no parameters.				            *
// * Date: 03/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU						*
// * References: Ideas for the Print function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


void BitVector::Print()
{
    for (size_t index = 0; index < size * 32; index++)
    {
        cout << index  + 1<< " value is:";
        if (Test(index))
            cout << " set";
        else
            cout << " not set";
        cout << endl;
    }
}


// **************************************************************************************
// * Function Name: Copy Constructor Function							                *
// * Description: Copy Constructor, creates a new BitVector object and allocates	    *
// * 	the content of the default constructor in to the new object that is created. 	*
// * Parameter Description: The parameter for this function is the &a, which we use in	*
// * 	our code to allocate the contents of size to a.size, and bvect to a.bvect.	    *
// * Date: 02/06/2020								                                    *
// * Author: Luciano Zavala, Information Technology Student at FSU						*
// * References: Ideas for the copy constructor come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


BitVector::BitVector(const BitVector &a)
{
    if (size != a.size)
    {
        bvect = nullptr;
        delete [] bvect;
        size = a.size;
        bvect = new int [size];
    }

    for (size_t index = 0; index < a.size; index++)
        bvect[index] = a.bvect[index];

    Unset();
}


//***************************************************************************************
//* Function Name: Assignment Constructor						                        *
//* Description: Assignment Constructor that creates a new BitVector and	            *
//*	 allocates the contents of the default constructor to the new object.		        *
//* Parameter Description: The parameter for this function is the &a, which we use in	*
//* 	our code to allocate the contents of size to a.size, and bvect to a.bvect.	    *
//* Date: 02/06/2020									                                *
//* Author: Luciano zavala,  Information Technology Student at FSU					    *
//* references: ideas for the assignment constructor come from dr. gaitros's web	    *
//*	conferences									                                        *
//* 	and lecture videos on the bit vector program.					                *
//***************************************************************************************


BitVector & BitVector::operator =(const BitVector &a)
{

    if (size != a.size)
    {

        bvect = nullptr;
        delete [] bvect;
        size = a.size;
        bvect = new int [size];

        if (bvect == 0)
        {
            cerr << "error! the number of bits is less than 0! please enter bits greater than that value." << endl;
            exit(EXIT_FAILURE);
        }

    }


    for (size_t index = 0; index < a.size; index++)
        bvect[index] = a.bvect[index];

    Unset();

    return *this;

}


// **************************************************************************************
// * Function Name: BitVector Destructor						                        *
// * Description: BitVector Destructor that de-allocates the memory of the BitVector	*
// *	Object, by deleting or destroying the array of bitvectors.			            *
// * Parameter Description: This function has no parameters.				            *
// * Date: 02/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU				        *
// * References: Ideas for the destructor come from Dr. Gaitros's Web Conferences	    *
// * 	and Lecture Videos on the Bit Vector Program. Also, from the Assignment 3	    *
// * 	Discussion.									                                    *
// **************************************************************************************


BitVector::~BitVector()
{
    bvect = nullptr;
    delete [] bvect;
}


// **************************************************************************************
// * Function Name: Return Size of BitVector Function               					*
// * Description: This function returns the size of the word, with a total	            *
// *	number of bits. When it is multiplied times 32, gives us the total bits.	    *
// * Parameter Description: This function has no parameters.				            *
// * Date: 03/06/2020									                                *
// * Author: Luciano Zavala,  Information Technology Student at FSU 				    *
// * References: Ideas for the size function come from Dr. Gaitros's Web Conferences	*
// * 	and Lecture Videos on the Bit Vector Program.					                *
// **************************************************************************************


size_t BitVector::Size() const
{
    return size * 32;
}


