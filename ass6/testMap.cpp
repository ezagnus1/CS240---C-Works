#include <iostream>
#include <utility>
#include <string>
#include "map.h"
using namespace std;

int main(){
	Map mapList;
	mapList.add(make_pair(45,new string("Bates Motel")));
	mapList.add(make_pair(36,new string("Breaking Bad")));
	mapList.add(make_pair(56,new string("Soul Eater")));
	cout << "The first list contents" << endl;
	mapList.displayAll();
	mapList.add(make_pair(25,new string("Address")));
	mapList.add(make_pair(42,new string("Brother")));
	mapList.add(make_pair(30,new string("Chemie")));
	mapList.add(make_pair(52,new string("Doom")));
	mapList.add(make_pair(60,new string("Eclipse")));
	mapList.add(make_pair(50,new string("Fahrenheit")));
	mapList.add(make_pair(51,new string("Garlic")));
	mapList.add(make_pair(51,new string("Hello")));
	cout << "The first list contents" << endl;
	mapList.displayAll();
	
	cout << "Height :: "<<mapList.height() << endl;
	
	Map mapList2;
	mapList2.add(make_pair(7,new string("Great")));
	mapList2.add(make_pair(14,new string("Assignment")));
	cout << "The anotherlist contents" << endl;
	mapList2.displayAll();

	if(mapList.find(60)){ cout << "The key " << "60"<< " was found" << endl;}
	if(mapList.find(6)){ cout << "The key " << "6"<< " was found" << endl;}
	if(mapList2.find(14)){ cout << "The key " << "14"<< " was found" << endl;}
	if(mapList.find(50)){ cout << "The key " << "50"<< " was found" << endl;}

	if(mapList.retrieve(51)!=nullptr){
		cout << *(mapList.retrieve(51)) << endl;
	}

	if(mapList.retrieve(42)!=nullptr){
		cout << *(mapList.retrieve(42)) << endl;
	}

	if(mapList2.retrieve(7)!=nullptr){
		cout << *(mapList2.retrieve(7)) << endl;
	}

	if(mapList.retrieve(56)!=nullptr){
		cout << "Before changing the value : " << *(mapList.retrieve(56)) << endl;
		*(mapList.retrieve(56)) = "Titanic";
		cout << "After changing the value : " << *(mapList.retrieve(56)) << endl;
	}

	if(mapList.empty()){
		cout << "This tree is empty" << endl;
	}
	cout << "This size is : "<< mapList.size() << endl;
	
	mapList.remove(45);
	mapList.displayAll();
	mapList.remove(36);
	mapList.displayAll();
	mapList.remove(60);
	mapList.displayAll();
	mapList2 = mapList;
}