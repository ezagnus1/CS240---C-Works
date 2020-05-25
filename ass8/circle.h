#ifndef Circle_
#define Circle_
#include "digraph.h"
using namespace std;

class Circle{
	public:
		void CreateCircle();
		//input: none
		//output: none
		//side effects: none
		void addMembers();
		//input: none
		//output: none
		//side effects: adds members to the circle
		void addEdges();
		//input: none
		//output: none
		//side effects: adds edges to the circle
		void CircleofMembers();
		//input: none
		//output: none
		//side effects: prints all members of the circle out to the screen  
		void NumberofMembers();
		//input: none
		//output: none
		//side effects: prints out the number of the all members of the circle to the screen
		void Edges();
		//input: none
		//output: none
		//side effects: prints out the number of friendships of the circle to the screen
		void findVertex();
		//input: none
		//output: none
		//side effects: prints out if a given vertex exists or not to the screen
		void findEdge();
		//input: none
		//output: none
		//side effects: prints out if a given edge exists or not to the screen
		void findAnotherEdge();
		//input: none
		//output: none
		//side effects: prints out if a given edge exists or not to the screen
		void remove();
		//input: none
		//output: none
		//side effects: removes a given edge from the circle
		void Successor();
		//input: none
		//output: none
		//side effects: prints out the successors of a given vertex to the screen
		void countPredecessor();
		//input: none
		//output: none
		//side effects: prints out the number of predecessors of a given vertex to the screen

	private:
		Digraph digraph;
		
};
#endif

