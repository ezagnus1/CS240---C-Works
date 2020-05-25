#include <iostream>
#include <utility>
#include <string>
#include "map.h"
using namespace std;

int main(){
	map mapList;
	mapList.add(make_pair(3,new string("Bates Motel")));
	mapList.add(make_pair(6,new string("Breaking Bad")));
	mapList.add(make_pair(20,new string("Soul Eater")));
	cout << "List contents" << endl;
	mapList.displayAll();
	map mapList2;
	mapList2.add(make_pair(7,new string("Great")));
	mapList2.add(make_pair(14,new string("Assignment")));
	cout << "Anotherlist contents" << endl;
	mapList2.displayAll();
	mapList.find(10);
	mapList.find(6);
	mapList2.find(14);
	if(mapList.retrieve(5)!=nullptr){
		cout << *(mapList.retrieve(5)) << endl;
	}

	if(mapList.retrieve(20)!=nullptr){
		cout << *(mapList.retrieve(20)) << endl;
	}

	if(mapList2.retrieve(7)!=nullptr){
		cout << *(mapList2.retrieve(7)) << endl;
	}
	
	mapList.remove(7);
	mapList.displayAll();
	mapList.remove(20);
	mapList.displayAll();
	mapList.remove(6);
	mapList.displayAll();
	mapList2 = mapList;
}
