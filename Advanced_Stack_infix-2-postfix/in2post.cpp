
// ********************************************************************
// * Name: Infix to Postfix Notation Code                             *
// * Description: A template Stack class designed to be used with     *
// *   any simple C++ and its focused to develop the infix to postfix *
// *   code.                                                          *
// * Author: Dr. David A. Gaitros                                     *
// * Date: February 17, 2021                                          *
// ********************************************************************

#include "Stack.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
using namespace cop4530;

int checkPre(string str);

void print(vector<string> &oVector);

bool Test(string str);

void infix2postfix(vector<string> &infix, vector<string> &oVector);

void convert(vector<string> &oVector);


int main()
{
    //Input vector declaration
    vector<string> iVector;

    //Output Vector declaration
    vector<string> oVector;
    string userInput;

    do{
        cout << "Enter infix expression (\"exit\" to quit): ";

        // get user input
        getline(cin, userInput);

        cout << "Infix Notation: " << userInput << endl;

        //Cleaning of old data
        oVector.clear();
        iVector.clear();

        //User input String stream
        stringstream sstream(userInput);

        //Create a token for the input
        while (sstream >> userInput)
        {
            iVector.push_back(userInput);
        }



        cout << "Postfix expression: ";
        infix2postfix(iVector, oVector);

        cout << "Postfix evaluation: ";
        convert(oVector);

    }while(userInput != "exit");


    return 0;
}

//**************************************************
//Check Pre Method: Assigns an order of operation  *
//    based on PEMDAS                              *
//**************************************************

int checkPre(string str)
{
    if (str == "(" || str == ")") {
        return (4);
    }
    else if (str == "^") {
        return (3);
    }
    else if(str == "*" || str == "/") {
        return (2);
    }
    else if(str == "+" || str == "-") {
        return (1);
    }
    else
        return 0;
}

//*****************************************************
// Print Method: Prints the content of the Stack     **
//*****************************************************

void print(vector<string> &oVector)
{
    for(auto & i : oVector)
    {
        cout << i << " ";
    }
}

//**************************************************************
// Test Method: Returns true if everything is alphanumeric    **
//**************************************************************

bool Test(string str)
{
    for(char i : str)
    {
        if (isalnum(i) == false)
        {
            return false;
        }
    }
    return true;
}

//*****************************************************************************
// Infix2Postfix Method: Converts a formula under the infix notation form    **
//    and returns a converted version of the formula into postfix notation.  **
//*****************************************************************************

void infix2postfix(vector<string> &infix, vector<string> &oVector)
{
    Stack<string> stack;

    //Loops through the expression
    for(auto & i : infix)
    {
        // evaluates if its not equal to 0
        if(checkPre(i) != 0)
        {
            //Evaluates if the expression starts with a parenthesis
            if((!stack.empty() && (stack.top() != "("))
            && (checkPre(stack.top()) >= checkPre(i)))
            {
                //Adds values to the stack while it extracts them
                while ((!stack.empty() && (stack.top() != "("))
                && (checkPre(stack.top()) >= checkPre(i)))
                {
                    oVector.push_back(stack.top());
                    cout << stack.top() << " ";
                    stack.pop();
                }
            }
            // Push the values to the stack
            stack.push(i);

            //Evaluates if its the end of a parenthesis
            if(i == ")")
            {
                // pop the ) right away
                stack.pop();

                //Pushes back the top value to the stack
                while(stack.top() != "(")
                {
                    cout << stack.top() << " ";
                    oVector.push_back(stack.top());
                    stack.pop();
                }

                // must be a ( so pop it
                stack.pop();
            }
        }
        else if(Test(i))
        {
            oVector.push_back(i);
            cout << i << " ";
        }
    }

    //While not empty print the values out
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        oVector.push_back(stack.top());
        stack.pop();
    }
    cout << endl;
}

//*****************************************************************************
// Infix2Postfix Method: Converts a formula under the infix notation form    **
//    and returns a converted version of the formula into postfix notation.  **
//*****************************************************************************

void convert(vector<string> &oVector)
{
    //Stack creation
    Stack<string> stack;

    //Value to determine if its a number or not
    bool isNumber = false;

    //Loops and evaluates if its or not a umber
    for (int i = 0; i < int(oVector.size()); i++)
    {
        if (Test(oVector[i]))
        {
            for (int ii = 0; ii < int(oVector[ii].size()); ii++)
            {
                // Evaluates for decimal numbers
                if ((isdigit(oVector[i][ii]) == true) || (oVector[i][ii] == '.'))
                    isNumber = true;
                else
                    break;
            }
        }
    }
    if (isNumber)
    {
        for (auto & i : oVector)
        {
            // if it is valid alphanumeric then push to stack
            if (Test(i))
            {
                stack.push(i);
            }

            //Evaluates if its an operator or parenthesis
            if (checkPre(i) != 0)
            {
                //Temporary float
                int tempInt = 0;

                // convert string to float
                float first = stof(stack.top());
                stack.pop();

                // pop item and convert next
                float second = stof(stack.top());
                stack.pop();

                if (i[0] == '*') {
                    tempInt = second * first;
                }
                else if (i[0] == '/') {
                    tempInt = second / first;
                }
                else if (i[0] == '+') {
                    tempInt = second + first;
                }
                else if (i[0] == '-')
                    tempInt = second - first;

                // convert to string then push string to stack
                stack.push(to_string(tempInt));
            }
        }
        print(oVector);

        cout << endl;

        // print out answer
        cout << "Results are: " << stack.top() << endl;
    }
    // if not a number
    else{
        print(oVector);
        // prints equal sign
        cout << "= ";
        print(oVector);
        cout << endl;
    }
}
