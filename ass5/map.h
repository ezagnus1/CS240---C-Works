#ifndef map_
#define map_
#include "mapInterface.h"
using namespace std;

class map:public MapInterface{
	
public:
	map();
	//Constructor
	~map();
	//Destructor
	map(const map& mapToCopy);
	//input: a map object
	//output: none
	//side effects: it creates a copy of the mapToCopy 
	map operator=(const map& object);
	//input: a map object
	//output: a map object
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
	//side effects: Map has one more element (if addition      		     	//              done)
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
	void displayAll() const; 
	//input: none
	//output: none
	//side effects: It displays all pairs(Key-Value) of the map object
	
private:
	int size1;
	class Node{
		
		public:
			ElementType data;
			Node *next;
	};
	Node *head;
	
};	

#endif

