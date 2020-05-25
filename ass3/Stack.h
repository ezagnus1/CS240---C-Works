#ifndef Stack_
#define Stack_

class Stack{

	public:
		Stack();
		//Constructor
		~Stack();
		//Destructor
		void Push(double newEntry);
		//input: a decimal number;
		//output: none
		//side effect: it pushes a new value to the stack 
		double Pop();
		//input: none
		//output: double value in which is top(start) of the stack
		//side effect: it removes a value in which is top(start) of the stack
		double Peek();
		//input: none
		//output: double value in which is top of the stack
		//side effect: it takes a value in which is top of the stack
		bool IsEmpty();
		//input: none
		//output: if stack is empty, it returns true. Otherwise return false
		//side effect: none
		int GetLength();
		//input: none
		//output: return length of the stack
		//side effect: none

	private:
		int size;
		class Node{
		public:
			double data;
			Node *next;
		};
		
		Node *head;
};

#endif
