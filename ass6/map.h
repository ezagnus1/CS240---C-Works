#ifndef map_
#define map_
#include "mapInterface.h"
using namespace std;

class Map:public MapInterface{
	
	public:
		Map();
		//Constructor
		~Map();
		//Destructor
		Map(const Map& mapToCopy);
		//input: a Map object
		//output: none
		//side effects: it creates a copy of the mapToCopy 
		Map operator=(const Map& object);
		//input: a Map object
		//output: a Map object
		//side effects: thanks to the operator, we are assigning an object elements to the other object.
		bool empty()const;
		//input: none
		//output: returns true if the Map is empty; else false
		//side effects: none
		int size()const;
		//input: none
		//output: returns the number of elements in the Map
		//side effects: none
		bool add(ElementType element);
		//input: an element (key and its associated value)
		//output: returns true if the key-value pair was 				     	//        added; else false(the key was found)
		//side effects: Map has one more element (if addition      		     		//              done)
		bool find(KeyType key) const;
		//input: a key
		//output: return true is an element with this key was 			//        found; else false
		//side effects: none
		ValueType retrieve(KeyType key) const;
		//input: a key
		//output: returns the value associated with key (a 			//        null pointer if the key was not found)
		//side effects: none
		bool remove(KeyType key);
		//input: a key
		//output: returns true if item is removed;
		//        else false (key not found)
		//side effects: Map has one less element (if remove 			//              done)
		void displayAll(); 
		//input: none
		//output: none
		//side effects: It displays all pairs(Key-Value) of the map object
		int height();
		//input: none
		//output: none
		//side effects: It gives height of the tree

	private:
		int heigh;
		int temp1;
		int size1;
		class Node{

		public:
			Node *right;
			Node *left;	
			ElementType data;
		};
		void Inorder(Node *temp);
		//input: a Node pointer
		//output: none
		//side effects: This function is used in order to display all items recursively in ascending order. It helps displayAll function.
		void Postorder(Node *temp);
		//input: a Node pointer
		//output: none
		//side effects: It is used to delete all items. It helps destructor.
		void Preorder(Node *temp);
		//input: a Node pointer
		//output: none
		//side effects: It is used to copy to given an object . It helps where copy constructor and operator are 
		void CalculateHeight(Node *temp);
		//input: a Node pointer
		//output: none
		//side effects: It is used to calculate the height of the tree recursively. It helps height function.
		Node *root;

};
#endif 
