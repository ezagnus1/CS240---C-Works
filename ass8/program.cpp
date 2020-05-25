#include <iostream>
#include "circle.h"
using namespace std;

void menu(Circle circle);
//input: a Circle object
//output: none
//side effects: This is where we select the options of the menu.
void output();
//input: none
//output: none
//side effects: It includes content of the menu.

int main(){
	Circle circle;
	circle.CreateCircle();
	circle.addMembers();
	circle.addEdges();
	menu(circle);
}

void output(){
	cout << "MENU" << endl;
	cout << "1)Who are the members of the circle of friends?" << endl;
	cout << "2)How many people belong to the circle of friends?" << endl;
	cout << "3)How many friendships are part of the circle of friends?" << endl;
	cout << "4)Is name a member of the circle of friends?" << endl;
	cout << "5)Who has name designated as a friend?" << endl;
	cout << "6)Has name1 designated name2 as a friend?" << endl;
	cout << "7)Has name1 been designated by name2 as a friend?" << endl;
	cout << "8)Remove name1 as a designated friend of name2" << endl;
	cout << "9)How many people have designated name as a friend?" << endl;
	cout << "0)Quit" << endl;
	cout << endl;
}

void menu(Circle circle){
	int i,x=0;
	while(1==1){
		output();
		cout << "Please select an option in the menu" << endl;
		cin >> i;
		switch(i){
			case 1: 
				circle.CircleofMembers();
				break;
			case 2:
				circle.NumberofMembers();
				break;
			case 3:
				circle.Edges();
				break;
			case 4:
				circle.findVertex();
				break;
			case 5:
				circle.Successor();
				break;
			case 6:
				circle.findEdge();
				break;
			case 7:
				circle.findAnotherEdge();
				break;
			case 8:
				circle.remove();
				break;
			case 9:
				circle.countPredecessor();
				break;
			case 0:
				x = 1;
				break;
		}
		if(x==1){
			break;
		}
	}
}
