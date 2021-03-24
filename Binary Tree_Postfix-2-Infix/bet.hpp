//
// Created by Luciano Zavala on 3/8/21.
//

#ifndef UNTITLED105_BET_HPP
#define UNTITLED105_BET_HPP

bool isOperand(string expression);

int checkPrecedence(string expression);


// ***************************************************************************************
// * Function Name: default Constructor						                             *
// * Description: Default constructor thatcreates a new binary three.                    *
// * Parameter Description: This function has no parameters.				             *
// * Date: 12/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previos Stack code            					                     *
// ***************************************************************************************


BET::BET()
{

    root = new BinaryNode;
}


// ***************************************************************************************
// * Function Name: Parameter Constructor				                                 *
// * Description: 2/rameter constructor that builds tree based on postfix expression.    *
// * Parameter Description: This function has no parameters.				             *
// * Date: 12/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previos Stack code            					                     *
// ***************************************************************************************


BET::BET(const string postfix)
{
    root = new BinaryNode;
    buildFromPostfix(postfix);
}


// ***************************************************************************************
// * Function Name: Copy Constructor						                             *
// * Description: the copy constructor has the duty of copying all the values in a tree  *
// *   to another.                                                                       *
// * Parameter Description: The parameter is refered to the stack that is to be copied.  *
// * Date: 10/03/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program.					                     *
// ***************************************************************************************


BET::BET(const BET& x): root{nullptr}
{

    root = clone(x.root);
}


// ***************************************************************************************
// * Function Name: Clone           						                             *
// * Description: Clone all nodes in subtree pointed to by t                             *
// * Parameter Description: The parameter is referred to the stack that is to be copied. *
// * Date: 08/03/2020									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and Lecture Videos on the Stack Program. Also from the Book.                     *
// ***************************************************************************************


BET::BinaryNode * BET::clone(BinaryNode *t) const
{
    // clone all nodes in subtree pointed to by t
    if(t == nullptr)
        return nullptr;
    else
        return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}


// ***************************************************************************************
// * Function Name: Destructor				             		                         *
// * Description: Deletes everything from the tree                                       *
// * Parameter Description: This function has no parameters.				             *
// * Date: 17/01/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


BET::~BET()
{
    // destructor
    makeEmpty(root);
}


// ***************************************************************************************
// * Function Name: Assignment Operator		             		                         *
// * Description: Implements the assignment operator between trees.                      *
// * Parameter Description: Binary Tree                                 	             *
// * Date: 12/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.                 					                     *
// ***************************************************************************************


const BET & BET::operator=(const BET & x)
{
    root = clone(x.root);
    return *this;
}


// ***************************************************************************************
// * Function Name: Make Empty          	             		                         *
// * Description: Deletes all the contents on the tree.                                  *
// * Parameter Description: Binary Tree                                 	             *
// * Date: 08/03/2021									                                 *
// * Author: Luciano Zavala,  Computer Science Student at FSU			     			 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and the resources given.  Also code from the book.                               *
// ***************************************************************************************


void BET::makeEmpty(BinaryNode* &t)
{
    // deletes all nodes in subtree pointed to by t
    if(t != nullptr)
    {
        // if it isnt empty then empty it
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}



// ***************************************************************************************
// * Function Name: Size            						                             *
// * Description: Returns the number of nodes on the tree.                               *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code					                                 *
// ***************************************************************************************


size_t BET::size()
{
    // return the number of nodes in the tree
    return (size(root));
}


// ***************************************************************************************
// * Function Name: leaf_nodes        						                             *
// * Description: Returns the number of leaf nodes on the tree.                          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.					                                 *
// ***************************************************************************************


size_t BET::leaf_nodes()
{
    // return the number of leaf nodes in the tree
    return (leaf_nodes(root));
}



// ***************************************************************************************
// * Function Name: Size            						                             *
// * Description: Returns the number of nodes on the tree.                               *
// * Parameter Description: This function has no parameters.				             *
// * Date: 13/02/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code. also code from the book.                         *
// ***************************************************************************************


size_t BET::size(BinaryNode *t)
{
    // returns number of nodes in subtree pointed to by t
    if(t == nullptr)
        return 0;
    else
        return(size(t->left) + size(t->right) + 1);
}


// ***************************************************************************************
// * Function Name: leaf_nodes        						                             *
// * Description: Returns the number of leaf nodes on the tree.                          *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the boook.                          *
// ***************************************************************************************



size_t BET::leaf_nodes(BinaryNode *t)
{
    // return number of leaf nodes in the subtree pointed to by t
    if(t == nullptr)
        return 0;
    else if((t->left == nullptr) && (t->right == nullptr))
        return 1;
    else
        return (leaf_nodes(t->left) + leaf_nodes(t->right));
}


// ***************************************************************************************
// * Function Name: empty           						                             *
// * Description: Returns if the tree is empty                                           *
// * Parameter Description: This function has no parameters.				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************


bool BET::empty()
{
    // return true if the tree is empty, else false
    if(root == nullptr) // if its an empty tree return true
        return true;
    return false;
}


//*************************************************************
//*           P O S T F I X   T O   I N F I X                 *
//*************************************************************

// ***************************************************************************************
// * Function Name: Build From Postfix          		                                 *
// * Description: Builds a tree from a postfix expression.Getting the operands as heads. *                                          *
// * Parameter Description: Postfix string                   				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************

bool BET::buildFromPostfix(const string& postfix)
{
    // build tree based on postfix expression
    string temp;
    string temp2;
    stack<BinaryNode*> myTree;
    stringstream s(postfix);

    int counter1 = 0;
    int counter2 = 0;

    if(postfix.empty())
    {
        cout << "Wrong postfix expression" << endl;
        root = nullptr;
        return false;
    }

    if(!empty())
        makeEmpty(root);

    while(s >> temp){ // use stringstream to tokenize input

        auto *myNode = new BinaryNode(temp); // create a node to hold tokenized input

        if(isOperand(temp))
        {
            // take all operands in and pushs to stack
            counter1++;
            myTree.push(myNode);	// push new node to stack
        }
        else if(checkPrecedence(temp) != 0)
        {
            // else if it is an operator (has precedence > 0)
            counter2++;
            if(counter1 == counter2){
                cout << "Wrong postfix expression" << endl;
                root = nullptr;
                return false;
            }
            else{
                myNode->left = myTree.top();
                myTree.pop();
                myNode->right = myTree.top();
                myTree.pop();
                myTree.push(myNode);
            }
        }
    }

    if(counter1 != counter2)
        root = myTree.top();

    if(myTree.empty() == true)
    {
        // this stops a crash from trying to pop from empty stack
        cout << "Error: wrong postfix expression" << endl;
        root = nullptr;
        return false;
    }

    return true;
}


// ***************************************************************************************
// * Function Name: Print Infix Expression        		                                 *
// * Description: prints an expression using infix notation.                             *
// * Parameter Description: No parameters.                   				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************


void BET::printInfixExpression()
{
    // print infix form (use private recursive function to help)
    printInfixExpression(root);
    cout << endl;
}


// ***************************************************************************************
// * Function Name: Print Postfix Expression        		                             *
// * Description: prints an expression using postfix notation.                           *
// * Parameter Description: No parameters.                    				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************


void BET::printPostfixExpression()
{
    // print postfix form (use private recursive function to help)
    printPostfixExpression(root);
    cout << endl;
}


// ***************************************************************************************
// * Function Name: Print Infix Expression        		                                 *
// * Description: prints an expression using infix notation.                             *
// * Parameter Description: No parameters.                   				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************


void BET::printInfixExpression(BinaryNode *n){
    // print infix expression
    bool closeParentheses = false;

    if(n != nullptr)
    {
        if(n->left == nullptr && n->right == nullptr)
            // if root node is valid, but has no children then just print it
            cout << n->element << " ";
        else{
            if(checkPrecedence(n->element) != 0 && checkPrecedence(n->right->element) != 0)
            {
                // test operator. prints the right side first
                if(checkPrecedence(n->element) >= checkPrecedence(n->right->element)){
                    if(checkPrecedence(n->element) == 2){
                        cout << "( ";
                        closeParentheses = true;
                    }
                }
            }

            printInfixExpression(n->right);

            if(closeParentheses)
                cout << ") ";
            closeParentheses = false; // set closeParentheses back to false

            cout << n->element << " ";
            if(checkPrecedence(n->element) != 0 && checkPrecedence(n->left->element) != 0)
            {
                // test for operator. print left side next
                if(checkPrecedence(n->element) >= checkPrecedence(n->left->element))
                {
                    cout << "( ";
                    closeParentheses = true;
                }
            }

            printInfixExpression(n->left);
            if(closeParentheses)
                cout << ") ";
            closeParentheses = false;
            // set closeParentheses back to false
        }
    }
}


// ***************************************************************************************
// * Function Name: Print Postfix Expression        		                             *
// * Description: prints an expression using postfix notation.                           *
// * Parameter Description: No parameters.                    				             *
// * Date: 10/03/2021									                                 *
// * Author: Luciano Zavala,  Information Technology Student at FSU						 *
// * References: Ideas for this constructor come from Dr. Gaitros's Web Conferences	     *
// * 	and my own previous Stack code.	Also code from the book.                         *
// ***************************************************************************************


void BET::printPostfixExpression(BinaryNode *n)
{
    // print postfix expression
    if(size(n) == 0) // prevent segfault on empty tree
        return;
    else if(root->left == nullptr && root->right == nullptr)
        cout << root->element << endl;
    else{
        printPostfixExpression(n->right); // print right nodes first
        printPostfixExpression(n->left); // print left nodes next
        cout << n->element << " ";
    }
}


//********************************************************************
//*                       Helper Functions                           *
//********************************************************************


bool isOperand(const string str)
{
    // test if operand
    for(int i = 0; i < int(str.size()); i++)
        if(isalnum(str[i]) == false)
            // check if alphanumeric
            return false;
    return true;
}

int checkPrecedence(const string str)
{
    // checks the precedence of given string
    if(str == "("|| str == ")")
        return (3);
    else if(str == "*" || str == "/")
        return (2);
    else if(str == "+" || str == "-")
        return (1);
    else
        return 0;
}
#endif //UNTITLED105_BET_HPP
