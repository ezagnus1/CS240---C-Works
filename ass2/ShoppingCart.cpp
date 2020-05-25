#include <iostream>
#include "ShoppingCart.h"
#include "LinkedList.h"
#include <sstream>
#include <string>
using namespace std;

ShoppingCart::ShoppingCart(){
	LinkedList cart;
}

bool ShoppingCart::Append(const ItemType & newEntry){
	if(cart.append(newEntry)==true){
		cout << "Item added" << endl;
	}
	return true;
	

}// APPEND FUNCTION ENDING


bool ShoppingCart::Insert(int newPos, const ItemType & newEntry){
	if(cart.insert(newPos,newEntry)==true){
		cout << "Item added at position " << newPos << endl;
	}
	else{
		cout << "This position is out of cart" << newPos << endl;
	}
	return true;
	
}// insert function ending


bool ShoppingCart::Remove(int pos){
	if(cart.remove(pos)==true){
		cout << "Item at position " << pos << " is removed" << endl;
	}
	else{
		cout << "This position is out of your cart." << endl;	
	}	
	return true;
}// remove ending


ItemType ShoppingCart::Retrieve(int position) const{
	ItemType a;
	a = cart.retrieve(position);
	return a;
} // retrieve function ending


void ShoppingCart::DisplayPosition(int pos) const{
	int a = cart.getLength();
	if(a<pos){
		cout << "There is no element in this position" << endl;
	}
	else{
		ItemType item = cart.retrieve(pos);
		cout << item.GetItemInfo() << endl;
	}
	
	return;

}// DisplayPosition function ending


void ShoppingCart::DisplayAllitem() const{
	int a = cart.getLength();	
	if(a==0){
		cout<< "There are no elements in your cart" << endl;
		return;
	}
	else{
		for(int i=1;i<=a;i++){
			ItemType item = cart.retrieve(i);
			cout << item.GetItemInfo() << endl;
			
		}
	}
	
	return;
	
}// DisplayAllitem function ending

void ShoppingCart::DisplayCostPosition(int pos) const{
	int a = cart.getLength();
	if(a<pos){
		cout<< "There is no elements in your cart" << endl;
	}
	else{
		ItemType item = cart.retrieve(pos);
		cout<< item.GetItemInfo2()<<endl;
	}
	



	return;

}// function ending

void ShoppingCart::DisplayCostItems() const{
	double total = 0.0;
	int a = cart.getLength();	
	if(a == 0){
		cout << "Total cost is $0" << endl;
		return;
	}
	else{
		for(int i=1;i<=a;i++){
			ItemType item = cart.retrieve(i);
			total += item.CalculatePrice(item.GetQuantity(),item.GetPrice());	
		}	
	}
	
	cout << "Total cost is $" << total << endl;
	 

}// function ending 


void ShoppingCart::DisplayNumberOfItem() const{
	int a = cart.getLength();	
	if(a == 0){
		cout << "There are no elements in the cart" << endl;
		return;
	}
	else{
		cout << "There are " << a << " items in the cart" << endl;
		return;
	}
}

			






















