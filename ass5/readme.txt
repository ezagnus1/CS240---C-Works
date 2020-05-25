In this assignment you will define and implement a subclass of the Map ADT (defined in mapInterface.h) using a value-oriented linked list as the data structure.  Your linked list may be kept in sorted order, in unsorted order, or may be a self-organizing list.  In addition to providing the methods described in the definition of the abstract class MapInterface, your Map class needs to have a default constructor, a destructor, a copy constructor and operator=.  All of these methods should have as their first statement an output line indicating that it has been called.

In addition of defining (in map.h) and implementing (in map.cpp) the Map class, you will need to write a program to test your Map class.  This program will be judged on how thoroughly it tests the Map class.  Your test program does not need to ask the user for any input.  The type of the key-value pairs to be used is defined in mapInterface.h.

To help in debugging your Map class add the following method:  

    void displayAll() const; 
    // write contents of the Map to cout

Note: The order in which the elements are displayed will depend on how you chose to store the elements in the linked list.

The .tar.gz file you submit should contain mapInterface.h, map.h, map.cpp, testMap.cpp and a makefile.  The Map class code that you submit will be tested using your test program and by a test program written by the instructor.

