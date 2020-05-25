#ifndef Digraph_
#define Digraph_
#include <string>
#include <utility>
#include <vector>
#include<list>

using namespace std;

typedef pair<string,string> ElementType;
 
class Digraph{
	
	public:
		Digraph();
		//Constructor
		void CreateDigraph();
		//input: none
		//output: none
		//side effects: none
		bool addVertex(string element);
		//input: a string variable
		//output: bool 
		//side effects: adds a vertex to the graph
		bool addEdge(ElementType element);
		//input: an ElementType variable
		//output: bool
		//side effects: adds an edge to the graph
		bool removeEdge(ElementType element);
		//input: an ElementType variable
		//output: bool
		//side effects: remove an edge from the graph
		bool IsEdge(ElementType element);
		//input: an ElementType variable
		//output: bool
		//side effects:	controls if the given edge exists 
		bool IsVertex(string element);
		//input: a string variable
		//output: bool
		//side effects:	controls if the given vertex exists 
		int NumberofVertices();
		//input: none
		//output: int variable
		//side effects:	returns the number of all members of the graph
		int NumberofEdges();
		//input: none
		//output: int
		//side effects:	returns the number of all edges of the graph
		vector<string>& Vertices();
		//input: none
		//output: vector
		//side effects: returns a vector holding the names of the members of the graph
		list<string>& Successors(string element);
		//input: string variable
		//output: list
		//side effects:	returns a list holding the successors of a given member
		int NumberofPredecessors(string element);
		//input: string variable
		//output: int
		//side effects:	returns the number of predecessors of a given member
			
	private:
		class Node{
			public:
				list<string> successors;
				list<string> predecessors;
		};	
		vector<string>vertex;
		vector<Node> v;
		int countEdges;
};

#endif
