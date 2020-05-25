#include <iostream>
#include "ShoppingCart.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

ShoppingCart readFile (ShoppingCart object, string a);
//input: a ShoppingCart object and one string.
//output: returns ShoppingCart object
//side effects: none
void OpenFile(string filename,ShoppingCart a);
//input: a string filename and one ShoppingCart object
//output: none
//side effects: if the file does not open, a message is written and if the file is empty, a message is written. 
string GetFilename();
//input: none
//output: returns a string
//side effects: prompts user to take a filename.


int main(){
	ShoppingCart a;
	string filename = "";
	filename = GetFilename();
	OpenFile(filename,a);
	return 0;
}

string GetFilename(){
	string a;
	cout << "Enter filename: " << endl;
	cin >> a;
	return a;
}

void OpenFile(string filename,ShoppingCart a){
	vector<string> v;
	ifstream inFS;
	string b;
	inFS.open(filename);

	if(!inFS.is_open()){
		cout << "Could not open file " << filename << endl;
		return;
	}

	while(getline(inFS,b)){
		v.push_back(b);
		a = readFile(a,b);
	}
	if(v.size()==0){
		cout << "This file is empty" << endl;
		return;
	}
	
	inFS.close();
	return;
}


ShoppingCart readFile (ShoppingCart object, string a){
	int number1;	
	double number2;	
	ItemToPurchase obj;	
	istringstream inSS,inss;
	inSS.str(a);
	inss.str(a);
	string c;
	int number = 0,count = 0;

	inSS >> c;
	if(c == "A"){ // if operation is append, it enters to this if
		while(inSS >> c){
			count++;
		}

		if(count==4){ // this "count" counts how much item is in a line except operation.If 4,so this is insert operation.If not, this is append operation  
			inss>>c;
			inss>>c;
			obj.SetName(c);
			inss>>number1;
			obj.SetQuantity(number1);
			inss>>number2;
			obj.SetPrice(number2);
			inss>>number;
			object.Insert(number,obj);
			return object;
		}
			else if(count==3){
				inss>>c;
				inss>>c;
				obj.SetName(c);
				inss>>number1;
				obj.SetQuantity(number1);
				inss>>number2;
				obj.SetPrice(number2);
				object.Append(obj);
				return object;
			}
	}

	else if(c == "R"){ // R represents remove operation
		inSS >> number;
		object.Remove(number);
		return object;
	}

	else if(c == "DA"){ // DA shows all items in your cart
		object.DisplayAllitem();
		return object;
	}

	else if(c == "D"){ // D shows an item at an given position 
		inSS >> number;
		object.DisplayPosition(number);
		return object;
	}

	else if(c == "DC"){ // DC displays item cost
		inSS >> c;
		if(isdigit(c.at(0))){ // if there is a number next to DC so, DisplayCostPosition function is called , if not, DisplayCostItems is called.
			stringstream geek(c);
			geek >> number;
			object.DisplayCostPosition(number); 
			return object;
		}

		else{
			object.DisplayCostItems();
			return object;
		}
	}

	else if(c == "DN"){ // DN displays number of items
		object.DisplayNumberOfItem();
		return object;
	}

}
