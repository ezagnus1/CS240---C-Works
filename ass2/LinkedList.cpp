#include "LinkedList.h"
#include "ListInterface.h"
#include <string>
using namespace std;

LinkedList::LinkedList(){
	head = nullptr;
	size = 0;
}

bool LinkedList::append(const ItemType & newEntry){
	Node *temp;
	if(head == nullptr){
		Node *ptr = new Node();
		ptr -> next = nullptr;
		ptr -> data = newEntry;
		head = ptr;
		size++;
		return true;
	}

	else{
		temp = head;
		Node *ptr = new Node();
		ptr->next = nullptr;
		ptr->data = newEntry;
		while((temp->next)!=nullptr){
		temp = temp->next;
		}
		temp->next = ptr;
		size++; 
		return true;
				
	}

}// APPEND FUNCTION ENDING


bool  LinkedList::insert(int newPos, const ItemType & newEntry){
	if (newPos==1){
		Node *temp;
		Node *ptr = new Node();
		ptr->data = newEntry;
		temp = head;
		head = ptr;
		ptr->next = temp;
		size++;
		return true;
	}
	else if(newPos!=1 && newPos<=size){
		Node *temp,*temp1;
		temp = head;
		Node *ptr = new Node();
		ptr->data = newEntry;
		for(int i=0;i<newPos-2;i++){
			temp = temp->next;
		}
		temp1 = temp->next;
		temp -> next = ptr;
		ptr -> next = temp1;
		size++;
		return true;
	}
	else if(newPos == size+1){
		Node *temp;
		temp = head;
		Node *ptr = new Node();
		ptr->next = nullptr;
		ptr->data = newEntry;
		while((temp->next)!=nullptr){
		temp = temp->next;
		}
		temp->next = ptr;
		size++; 
		return true;
	}
	else{
		return false;
	}

}// insert function ending


bool  LinkedList::remove(int pos){
	Node *temp,*temp1,*ptr;
	temp=head;
	if(pos == 1){
		head = temp->next;
		delete temp;
		temp = nullptr;
		size--;
		return true;
	}
	else if(pos!=1 && pos<size){
		for(int i=0;i<pos-2;i++){
			temp = temp->next;
		}	
		ptr = temp->next;
		temp1 = temp -> next -> next;
		temp->next = temp1;
		delete ptr;
		ptr = nullptr;
		size--;
		return true;
	}

	else if(pos==size){
		while(temp->next!=nullptr){
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = nullptr;
		delete temp;
		temp = nullptr;
		size--;
		return true;
	}

	else {
		return false;
	}

}// remove ending


ItemType  LinkedList::retrieve(int position) const{
	Node *temp = head;
	
	for(int i=1;i<position;i++){
		temp = temp->next;
	}
	return temp->data;

} // retrieve function ending



bool  LinkedList::isEmpty() const{
	if(size==0){
		return true;
	}
	else{
		return false;
	}

}// isEmpty function ending



int  LinkedList::getLength() const{
	return size;

} // getLength function ending
