#ifndef Priority_Queue_
#define Priority_Queue_
#include "Call.h"

class PriorityQueue{
	
	public:
		PriorityQueue();
		//Constructor
		~PriorityQueue();
		//Destructor
		void enqueue(Call& element); 
		//input: this function pushes taken elements to the waitList as their highest priorities  
  		// output: none
		void dequeue();
		//input: none
  		// output: none
		// removes first element in the waitList
		Call front();
		//input: none
  		// output: returns a Call object
		int GetLength();
		//input: none
  		// output: returns the length of the waitList
		bool isEmpty();
		//input: none
  		// output: if waitList is empty,it returns true , otherwise returns false

	private:
		int size;
		class Node{
			public:
				Call data;
				Node *next;	
		};
		Node *head;
};

#endif
