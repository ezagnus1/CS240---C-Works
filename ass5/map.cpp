#include <iostream>
#include "map.h"
using namespace std;

map::map(){
	size1=0;
	head=nullptr;
}

map::~map(){
	if(size1==0){
		
	}
	cout << "Destructor called"<<endl;
	Node *temp=head;
	while(head!=nullptr){
		temp = head;
		head = temp->next;
		delete (temp->data).second;
		delete temp; 
	}
}

map:: map(const map& mapToCopy){
	cout << "Copy Constructor called"<<endl;
	head = nullptr;
	size1 = 0;
	Node *temp;
	temp = mapToCopy.head;
	while(temp!=nullptr){
	KeyType key = (temp->data).first;
	ValueType value = new string(*(temp->data).second);
	ElementType element;
	element = make_pair(key,value);
	add(element);
	temp = temp->next;
	}
	size1 = mapToCopy.size1;
	return;
}



map map :: operator=(const map& object){
	cout << "Operator called"<<endl;
	if(size1!=0){
		Node *temp=head;
		while(head!=nullptr){
		temp = head;
		head = temp->next;
		delete (temp->data).second;
		delete temp; 
		}	
	}
	head = nullptr;
	size1 = 0;
	Node *temp;
	temp = object.head;
	while(temp!=nullptr){
	KeyType key = (temp->data).first;
	ValueType value = new string(*(temp->data).second);
	ElementType element;
	element = make_pair(key,value);
	add(element);
	temp = temp->next;
	}
	size1 = object.size1;
	return object;
}

bool map::empty()const{
	if(size1==0){
		return true;
	}
	else{
		return false;
	}
}

int map::size()const{
	return size1;
}

bool map::add(ElementType element){
	if(size1==0){
		Node *ptr = new Node();
		ptr->data = element;
		ptr->next = nullptr;
		head = ptr;
		size1++;
		return true;
	}
	else{
		Node *temp;
		Node *ptr = new Node();
		temp = head;
		while(temp->next!=nullptr){
			temp = temp->next;
		}
			ptr->data = element;
			ptr->next = nullptr;
			temp->next = ptr;
			size1++;
			return true;
	}
		
}

bool map::find(KeyType key) const{
	if(size1==0){
		cout << "The key was " << key << " not found because the size is zero" << endl;
		return false;
	}
	else{
		Node *temp;
		temp = head;
		while(temp!=nullptr){
			if(temp->data.first==key){
				cout << "The key " << key <<  " was found" << endl;
				return true;
			}
			temp = temp->next;
		}
		cout << "The key " << key <<" was not found" << endl;
		return false;
	}
	
}//function ending

ValueType map::retrieve(KeyType key) const{
	if(size1==0){
		return nullptr;
	}
	else{
		Node *temp;
		temp = head;
		while(temp!=nullptr){
			if(temp->data.first==key){
				return (temp->data.second);
			}
			temp = temp->next;
		}
		return nullptr;
	} // else ending
}

bool map::remove(KeyType key){
	if(size1==0){
		return false;
	}
	
	Node *temp,*temp1;
	temp1=head;
	temp=head;
		if(temp->data.first==key){
				head = temp->next;
				delete (temp->data).second;
				delete temp;
				size1--;
				return true;
		}
		
		while(temp->next!=nullptr){
			temp=temp->next;
			if(temp->data.first==key){
				temp1->next = temp->next;
				delete (temp->data).second;
				delete temp;
				size1--;
				return true;
			}
			temp1=temp1->next;
		}	
	return false;
}

void map::displayAll() const{
	if(size1==0){
		return;
	}
	else{
		Node *temp;
		temp=head;
		while(temp!=nullptr){
			cout << "Key: " << temp->data.first << "    " << "Value: " << *(temp->data.second);
			cout << endl;
			temp=temp->next; 
		}
	}
	cout << endl;
} 
