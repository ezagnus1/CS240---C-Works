Part 1 - Define and implement a class Stack.  Your class must provide the stack behavior described in zybooks and in class.  Implement the stack using a linked list.  Your class should implement a destructor but does not need to implement  a copy constructor or operator=.

Part 2 - write a  well decomposed program that uses an object of your Stack class to evaluate a postfix expression using the algorithm shown in class.  This program  should:
prompt the user for the name of an input file
open that file
for each line of the input file
read a postfix expression
evaluate the postfix expression
write to an output file the postfix expression and the result of evaluating it
The text file that contains the postfix expressions will have the following format.  Each line will contain one postfix expression.  Operands will be decimal numbers and the only operators will be +, *, -  and /.  Tokens (operators and operands) will be separated by at least one blank.  An example of an input file follows:

            23.8  4 * 19.5  2 - + 
            6.8  10.5 - 
            36 6 /

You can assume that the input file is formatted as described above and that all postfix expressions are legal.

The output file your program creates as a result of reading the input file shown above should look something like:

The result of evaluating:   23.8  4 * 19.5  2 - +   is  112.7
The result of evaluating:  6.8  10.5 - is  -3.7
The result of evaluating:  36 6 /  is  6.0 

The .tar.gz file you submit should contain Stack.h, Stack.cpp, yourProgram.cpp, a makefile and several files 
(including the one shown above) containing postfix expressions that you used to test your program. 

