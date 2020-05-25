Write a program that creates and manages of a circle of friends.  The relationships among the members of the circle of friends will be represented as a directed graph where each vertex is the name of a member of the circle and each directed edge represents a friendship.  For example the directed edge <Joe, Jane> means that Joe has designated Jane as his friend.  You will need to define and implement a Digraph class to store the collection of  vertices and directed edges.  All input to the program will be from the keyboard  and all output from the program will be to the screen.

Your program will be built from the following files:

digraph.h - defines a class Digraph
this class will need public methods to:        
create an empty digraph
add a vertex to the digraph
add a directed edge to the digraph
remove a directed edge from the digraph
find out if there is a directed edge from one vertex to another vertex
find out if a vertex is in the digraph
return the number of vertices in the digraph
return the number of edges in the digraph
return the vertices of the digraph
return the successors of a vertex
return the number of predecessors of a vertex

in the private section implement the class using a vector<T> to store the vertices and a list<T> to store the edge list (successors) of each vertex.  You can assume that there will be a maximum of 20 vertices.      
digraph.cpp - implements the class Digraph.  Use functions from <algorithm> whenever possible.  There should be no terminal output done in this file.  If you use output statements for debugging purposes, comment them out before submitting the assignment.

circle.h - defines a class Circle which has-a Digraph as a private data member. The Circle class needs methods that can be called from the program to create a circle of friends, to add members and friendships to it and to respond to each of the queries selected from a menu presented by the program.  

circle.cpp - implements the class Circle.  All output to the screen (other than the menu) will done in this class.

program.cpp - which has-a Circle and uses it do the following:
create a circle of friends by adding members (a name) and friendships (2 names) to the Circle
you can hard code the members and friendships, i.e. no user input is needed
members have unique names
when adding a friendship, both names must already be members

presents the user with a menu of the following options:
who are the members of the circle of friends?
how many people belong to the circle of friends?
how many friendships are part of the circle of friends?
is name a member of the circle of friends?
who has name designated as a friend?
has name1 designated name2 as a friend?
has name1 been designated by name2 as a friend?
remove name1 as a designated friend of name2
how many people have designated name as a friend?
quit
(for 3 extra points) remove name as a member of the circle of friends

The .tar.gz file you submit should contain the 5 files shown above and a makefile.

