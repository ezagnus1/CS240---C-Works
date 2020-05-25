#include "PriorityQueue.h"
using namespace std;

PriorityQueue::PriorityQueue(){
	size = 0;
	head = nullptr;
}

PriorityQueue::~PriorityQueue(){
	Node *temp;
	temp = head;
	while(head!=nullptr){
		temp = head;
		head = temp->next;
		delete temp;
	}
}

void PriorityQueue::enqueue(Call& element){

	if(size==0){
		Node *ptr = new Node();
		ptr->data = element;
		ptr -> next = nullptr;
		head = ptr;
		size++;
		return;
	}
	else{
		Node *temp1 = head;
		Node *temp = head;
		Node *ptr = new Node();
		int x=0;
		if(temp->data > element){
			ptr->data = element;
			ptr->next = temp; 
			head = ptr;
			size++;
			return;
		}
		while((temp->data <= element) && (temp->next != nullptr)){
			temp = temp->next;
			
			if(x!=0){
				temp1 = temp1->next;
			}
			x++;
		}
		if(temp->next == nullptr){
			ptr->data = element;
			ptr->next = nullptr;
			temp->next = ptr;
			size++;
			return;
		}
		if(temp->next != nullptr){
			ptr->next = temp;			
			ptr->data = element;
			temp1->next = ptr;
			size++;
			return;
		}
	
	}	

	
}

Call PriorityQueue::front(){
	Node *temp = head;
	return temp->data;
	
}

void PriorityQueue::dequeue(){
	if(size==0){
		return;
	}
	Node *temp = head;
	head = temp->next;
	delete temp;
	size--;
	return;
}

int PriorityQueue:: GetLength(){
	return size;
}

bool PriorityQueue::isEmpty(){
	if(size==0){
		return true;
	}
	else{
		return false;
	}
}
