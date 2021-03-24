// ********************************************************************
// * Name: Stack Class                                                *
// * Description: A template Stack class designed to be used with     *
// *   any simple C++ and its focused to develop the infix to postfix *
// *   code.                                                          *
// * Author: Dr. David A. Gaitros                                     *
// * Date: February 14, 2021                                          *
// ********************************************************************

#ifndef UNTITLED103_STACK_H
#define UNTITLED103_STACK_H
#include <iostream>
#include <vector>

namespace cop4530
{
    template <typename T>
    class Stack{
    private:
        std::vector<T> v;

    public:
        Stack();                                 // default constructor
        ~Stack();                                // destructor
        Stack(const Stack<T> &);                 // copy constructor
        Stack(Stack<T> &&);                      // move constructor
        Stack<T> & operator=(const Stack<T> &);  // copy assignment operator
        Stack<T> & operator=(Stack<T> &&);       // move assignment operator
        bool empty() const;                      // Empty function
        void clear();                            // Clear function
        void push(const T& x);                   // Constant Push
        void push(T && x);                       // Push
        void pop();                              // Pop
        T& top();                                // Returns top
        const T& top() const;                    // Constant top
        int size() const;                        // Size of vector

        void print(std::ostream& os, char ofc = ' ') const;
        std::vector<T> getVector() const;
    };

    //Assignment Operator
    template <typename T>
    std::ostream & operator << (std::ostream & os, const Stack<T> & a);

    //Comparison Operators
    template <typename T>
    bool operator == (const Stack<T> & a, const Stack<T> & b);

    //Inequality Operators
    template <typename T>
    bool operator != (const Stack<T> & a, const Stack<T> & b);

    //Comparison of bigger than Operator
    template <typename T>
    bool operator <= (const Stack<T> & a, const Stack<T> & b);

#include "Stack.hpp"
}

#endif //UNTITLED103_STACK_H
