#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(){
	size=0;
	head = nullptr;
}

Stack::~Stack(){
	//cout << "Destructor called" << endl;
	Node *temp;
	temp = head;
	while(head!=nullptr){
		temp = head;
		head = temp->next;
		delete temp;
		
	}
}

void Stack::Push(double newEntry){
	if(IsEmpty()){
		Node *ptr = new Node();
		ptr->data = newEntry;
		ptr->next = nullptr;
		head = ptr;
		size++;
	}
	else{
		Node *temp;
		temp = head;
		Node *ptr = new Node();
		ptr->data = newEntry;
		ptr->next = temp;
		head = ptr;
		size++;
	}
}

double Stack::Pop(){
	double a;
	Node *temp;
	temp = head;
	a = temp->data;
	head = temp->next;
	delete temp;
	temp = nullptr;
	size--;
	return a;
}

double Stack::Peek(){
	return head->data;
}


bool Stack::IsEmpty(){
	if(size==0){
		return true;
	}

	else{
		return false;
	}
}

int Stack::GetLength(){
	return size;
}
