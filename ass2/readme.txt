Write a program that manages an on-line shopping cart for a user.  Your program will be built from the following components:
the ItemToPurchase class that you wrote for Lab 3

a class named LinkedList that implements the List interface defined in ListInterface.h using a linked list.
the only change you will make to ListInterface.h is to make ItemToPurchase the ItemType
a class named ShoppingCart - a ShoppingCart holds the items the user desires to purchase.  This class will have as a data member:  LinkedList cart;
The class will  need methods to:
add an item to the cart (put it at the end)
add an item to the cart (put it at position i)
remove the item at position i
display the item at position i
display the items in the cart, numbering them 1 through n (number of items currently in the cart)
display the total cost of the item at position i
display the total cost for all items in the cart
display the number of items in the cart

A program (decomposed into functions) that manages the contents of a shopping cart.  The program needs to:
create a ShoppingCart object
open an input file (name provided by program user)
read the input file
for each line
perform the operation specified
for the add and remove operations display a message indicating whether the operation succeeded or failed
Each line of the input file contains one of  the following operations:
A description  cost quantity                (add an item with the description, cost
                                                              and quantity to the end of the List)
A description cost quantity pos          (add an item with the description, cost
                                                              and quantity at position pos of the List)
R pos                                                   (remove the item at position pos)
D pos                                                   (display the item at position pos)   
DA                                                      (display all items in the cart)
DC pos                                                (display the total cost of the item at position pos)
DC                                                      (display the total cost of all items in the cart)
DN                                                      (display the number of items in the cart)
You can assume that the input file will be formatted as described above.  You cannot assume that the position given is valid (for example you cannot remove the item at position 6 if there are 5 items in the list).
The .tar.gz file you submit should contain all the files needed to execute your program, a makefile and input files for the program to read from.  One of the input files must be test1.txt.  
