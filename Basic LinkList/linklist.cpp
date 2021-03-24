// Created by Luciano Zavala 16/07/2020
// ********************************************************************
// * Name: Double linklist Program                                    *
// * Description: The Code is designed to implement a basic linklist. *
// *   using different functions such as the constructor, destructor, *
// *   Empty, Size, Find Insert, Delete and some more. all this       *
// *   functions are designed to cread a link (node) with pointers    *
// *   between a structure called pie or cake and the class that      *
// *   stores the methods to use such structure. The program also is  *
// *   designed to get a file and store the data in the structure and *
// *   test the methods.                                              *
// * Author: Luciano Zavala (linklist.cpp)                            *
// * Date: July 16, 2020                                              *
// ********************************************************************
#include<iostream>
#include "linklist.h"
#include <iomanip>
using namespace std;


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor that assigns the default values to the database.   *
// * Parameter Description: This function has no parameters.				             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


LinkList::LinkList()
{

  head = new PieCake_struct;
  tail = new PieCake_struct;
  head->id = -1;
  head->lname = "                         ";
  head->fname = "                         ";
  head->mi = ' ';
  head->sex = ' ';
  head->pORc = ' ';
  tail->id = 999999;
  tail->lname = "ZZZZZZZZZZZZZZZZZZZZZZZZZ";
  tail->fname = "ZZZZZZZZZZZZZZZZZZZZZZZZZ";\
  tail->mi = 'Z';
  tail->sex = 'Z';
  tail->pORc = 'Z';
  head->next = tail;
  head->prev = nullptr;
  tail->prev = head;
  tail->next = nullptr;

  current = nullptr;
  count = 0;

}


// ***************************************************************************************
// * Function Name: Destructor              			                                 *
// * Description: The function is designed to destroy all the contents inside the class. *
// * Parameter Description: no parameters.                                               *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


LinkList::~LinkList()
{
    PieCake_struct * check = head;

    // loop to erase the data
    while (head)
    {
        head = check-> next;
        delete check;
        check = head;
    }
}


// ***************************************************************************************
// * Function Name: Empty Function					                                     *
// * Description: The function return true if the content of the list is empty, false    *
// *   otherwise.                                                                        *
// * Parameter Description: This function has no parameters.				             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


bool LinkList::Empty()
{
    // Returns true if next == tail
    return (head->next == tail);
}


// ***************************************************************************************
// * Function Name: Size Function					                                     *
// * Description: The function returnsThe count of the records added to the list.        *
// * Parameter Description: This function has no parameters.				             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


int LinkList::Size()
{
    // Returns count of the records
    return count;
}


// ***************************************************************************************
// * Function Name: Find Function					                                     *
// * Description: The function is designed to find an specific record based on the id    *
// *   number. The function returns true if the id is found, false otherwise.            *
// * Parameter Description: This function has the Id number parameter to get the input.  *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


bool LinkList::Find(const int idnumber)
{

    current = head->next;

    // Loop to find the record
    while(current != tail)
    {
        // If the record is found return true
        if (current->id == idnumber)
        {
            return true;
        }

        // Pass to next record
        current = current->next;
    }
    // Return false otherwise
    return false;
}


// ***************************************************************************************
// * Function Name: Insert Function					                                     *
// * Description: The function is designed to inset a record and to locate it under      *
// *   alphabetical order. this sis done by a loop that checks the ascii value of the    *
// *   last name and locates it once fits the numerical order.                           *
// * Parameter Description: This function struct pointer as parameters that takes the    *
// *   record and applies it to the class.                                               *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************



void LinkList::Insert(PieCake_struct *p)
{
    // Initialize the record
    PieCake_struct * check = head -> next;

    //add one to the counter of records
    count++;
    current = new PieCake_struct;
    current = p;

    // Loop to locate the record alphabetically checkin the ascii values
    while (current -> lname > check -> lname)
    {
        check = check->next;
    }

    // Locate the record and the pointer
    current -> prev = check -> prev;
    current -> next = check;
    check -> prev -> next = current;
    check -> prev = current;

}


// ***************************************************************************************
// * Function Name: Delete Function					                                     *
// * Description: The function is designed to locate a record in the list thought a      *
// *   loop and deletes the record, it also reduces the counter of records by one.       *
// * Parameter Description: This function has no parameters.                             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


bool LinkList::Delete()
{
    // Initialize the record
    PieCake_struct *search = head->next;

    // Loop until the list is over
    while (search != tail)
    {
        // Identify if the record is found
        if (Find(current->id))
        {
            // If the record is found, delete it
            search = current;
            search->prev->next = search->next;
            search->next->prev = search->prev;
            delete search;

            // Reduce the counter by one
            count--;

            // Return true if the deleting process was successful
            return true;
        }
        search = search->next;
    }

    // Otherwise return false
    return false;
}


// ***************************************************************************************
// * Function Name: Print Function					                                     *
// * Description: The function is designed to print as the names says the ledger that    *
// *   describes the data. and the last analytical text about the number of pies and     *
// *   number of cakes present in the data. it also prints the size of the list.         *
// * Parameter Description: This function has no parameters.                             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


void LinkList::Print()
{
    // Print Ledger:
    cout << "******* The Cheesecake Survey *******" << endl;
    cout << "ID       Last Name        First Name           MI          Sex           Pie/Cake " << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    // Print the Complete list using the list function
    List();
    cout << endl;

    // Print the size of the list
    cout << "Total Surveyed: " << Size() << endl;

    // Prints the count of Pie related records
    cout << "People who thought Cheesecake was Pie: " << CountPie() << endl;
    // Prints the count of Cake related records
    cout << "People who thought Cheesecake was Cake: " << CountCake() << endl;
    cout << "\n";
}


// ***************************************************************************************
// * Function Name: list Function					                                     *
// * Description: The function is designed to print the list containing all the records  *
// *   using the standard output.                                                        *
// * Parameter Description: This function has no parameters.                             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


void LinkList::List()
{
    // Initialize counter
    current = head -> next;

    // Identify the the records
    if (Find(current -> id))
    {
        // error message if the list is empty
        if (Empty())
        {
            cout << "The list is empty!" << endl;
            return;
        }

        // Loop until the end of the list is reached
        while (current != tail)
        {
            // Standard output print
            cout << current -> id << "            "<<  current -> lname;
            cout << "            " << current -> fname;
            cout << "         " << current -> mi << "           ";

            // If sex == M print Masculine, else sex == F print Femenine
            if ( current ->sex == 'M')
            {
                cout << "Masculine" << "          " ;
            } else
                cout << "Femenine" << "           ";

            // If pORc == P print Pie, else pORc == C print Cake
            if (current -> pORc == 'P')
            {
                cout << "Pie"<<"           " << endl;
            }else
                cout << "Cake" <<"           " << endl;

            // Go to the next record
            current = current -> next;
        }
    }
    else
        cout << "\n";

}


// ***************************************************************************************
// * Function Name: CountPie Function					                                 *
// * Description: The function is designed to identify the records that refer to Pie and *
// *   count them. It also returns the value of the counter.                             *
// * Parameter Description: This function has no parameters.                             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


int LinkList::CountPie()
{
    // Initialize counter to zero
    int pie_count = 0;

    // Initialize current
    current = head->next;

    // Loop until the end of the list is reached
    while (current != tail)
    {
        // If record == Pie add 1 to counter
        if(current->pORc == 'P')
        {
            pie_count += 1;
        }
        current = current->next;
    }

    // Return the value of the counter
    return pie_count;
}


// ***************************************************************************************
// * Function Name: CountCake Function					                                 *
// * Description: The function is designed to identify the records that refer to Cake and*
// *   count them. It also returns the value of the counter.                             *
// * Parameter Description: This function has no parameters.                             *
// * Date: 20/06/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the linklist Program.					                     *
// ***************************************************************************************


int LinkList::CountCake()
{
    // Initialize counter to zero
    int cake_count = 0;

    // Initialize current
    current = head->next;

    // Loop until the end of the list is reached
    while (current != tail)
    {
        // If record == Cake add 1 to counter
        if(current->pORc == 'C')
        {
            cake_count += 1;
        }
        current = current->next;
    }

    // Return the value of the counter
    return cake_count;
}

