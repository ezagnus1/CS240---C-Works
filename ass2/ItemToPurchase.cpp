#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase(){
	
}

ItemToPurchase::ItemToPurchase(string name,double price,int quantity){
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}

	
void ItemToPurchase::SetName(string a){
	name = a;
	return;
}	

void ItemToPurchase::SetPrice(double a){
	price = a;
	return;
}	

void ItemToPurchase::SetQuantity(int a){
	quantity = a;
	return;
}

string ItemToPurchase::GetItemInfo()const{
	return name +" "+ to_string(quantity)+" " + "@" + " "+ "$"+ to_string (price);
}

string ItemToPurchase::GetItemInfo2()const{
	return name +" "+ to_string(quantity) +" " + "@" + " "+ "$"+ to_string(quantity*price); 
}

double ItemToPurchase::CalculatePrice(int quantity, double price){
	double b = price*quantity;
	return b;
}


double ItemToPurchase::GetPrice(){
	return this->price;
}

int ItemToPurchase::GetQuantity(){
	return this-> quantity;
}
string ItemToPurchase::GetName(){
	return this-> name;
}
ostream & operator<< (ostream & out, const ItemToPurchase & f) {
	out << f.GetItemInfo();
	return out;
} 

