
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
#include <string>
#include "tlist.h"

using namespace std;

template <typename T>
void PrintList(const TList<T>& L, string label) // Print function sourced from Professors example driver.cpp
{
    cout << label << " size is: " << L.GetSize() << "\n"
         << label << " = ";
    L.Print(cout);
    cout << "\n\n";
}

int main(void)
{
    TList<int> List1;
    TList<double> List2;

    cout<<"Prints the empty lists: \n";
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout<<"It should print List is empty: \n";
    if(List1.IsEmpty())
    {
        cout << "List is Empty" << endl;
    }
    else
        cout << "List is not Empty" << endl;

    cout<<"test for inset back method: \n";

    for (int i = 0; i < 15; i++)
    {
        List1.InsertBack(i*2 + i);
        List2.InsertBack(i*3 + i);
    }
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout<<"It should print List is  not empty: \n";

    if(List1.IsEmpty())
        cout << "List is Empty\n" << endl;
    else
        cout << "List is not Empty\n" << endl;

    cout<<"test for InsertFront method: \n";

    for (int i = 1; i <= 15; i++)
    {
        List1.InsertFront(i*100);
        List2.InsertFront(i*200);
    }

    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout<<"test for RemoveBack method: \n";

    for (int i = 0; i < 10; i++)
    {
        List1.RemoveBack();
        List2.RemoveBack();
    }
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    for (int i = 0; i < 10; i++)
    {
        List1.RemoveFront();
        List2.RemoveFront();
    }
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout << "Testing some inserts with an iterator\n\n";

    TListIterator<int> itrList1 = List1.GetIterator();
    TListIterator<double> itrList2 = List2.GetIteratorEnd();

    cout << " Test for the insert method: \n";

    for (int i = 0; i < 6; i++)
    {
        List1.Insert(itrList1, i*1000);
        itrList1.Next();
    }
    PrintList(List1, "List1");

    for (int i = 0; i < 6; i++)
    {
        List2.Insert(itrList2, i*2000);
        itrList2.Previous();
        itrList2.Previous();
    }
    PrintList(List2, "List2");

    //test iteration from back to front
    while (itrList1.HasPrevious())
        itrList1.Previous();

    //test iteration from front to back
    while (itrList2.HasNext())
        itrList2.Next();

    //test for inset method at the beginning
    List1.Insert(itrList1, 1);

    List1.Insert(itrList1, 2);

    List1.Insert(itrList1, 3);

    //test for inset method at the end
    List2.Insert(itrList2, 4);

    List2.Insert(itrList2, 5);

    List2.Insert(itrList2, 6);

    cout << "test for inset method at the beginning and at the end: \n";
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout << "test for the remove method: \n";

    for (int i = 0; i < 5; i++)
    {
        itrList1.Next();
        itrList1 = List1.Remove(itrList1);

        itrList2.Previous();
        itrList2.Previous();
        itrList2 = List2.Remove(itrList2);
    }
    PrintList(List1, "List1");
    PrintList(List2, "List2");

    cout << "The First element of List 1 is: " << List1.GetFirst() << endl;
    cout << "The Last element of List 2 is: " << List2.GetLast() << "\n\n";

    // building another list
    TList<int> List3;
    for (int i = 0; i < 10; i++)
        List3.InsertBack(i * 3 + 1);

    PrintList(List3, "List3");

    // Testing + overload:
    TList<int> List4 = List1 + TList<int>(21, 5);

    TList<int> List5;
    List5 = List4 + List1;

    PrintList(List4, "List4");
    PrintList(List5, "List5");


    return 0;
}