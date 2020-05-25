#include <iostream>
#include "circle.h"
using namespace std;

void Circle::CreateCircle(){
	digraph.CreateDigraph();
}

void Circle::addMembers(){
	int i=0;
	string name;
	cout << "Please enter the name you wanted to add and to quit please enter the 0(zero)" << endl;
	while(i<20){
		cin >> name;
		if(name == "0"){
			break;
		}
		if(digraph.addVertex(name)){
			cout << name << " is added" << endl;
		}
		else{
			cout << name << " could not added" << endl;
		}
		i++;
	}
}

void Circle::addEdges(){
	ElementType element;
	string name1,name2;
	while(1==1){
		cout << "Enter the two names you wanted to make a friendship between two people and to quit please enter name1 or name2 as 0(zero) " << endl;
		cin >> name1;
		cin >> name2;
		if(name1 == "0" || name2 == "0"){
			break;
		}
		element = make_pair(name1,name2);
		if(digraph.addEdge(element)){
			cout << "The edge was added" << endl;
		}
		else{
			cout << "The edge could not added" << endl;
		}
	}
}

void Circle::CircleofMembers(){
	vector<string> v1 = digraph.Vertices();
	cout << "The members of the circle are: " << endl;
	for(int i=0;i<v1.size();i++){
		cout << v1.at(i) << endl;
	}
	cout << endl;
}

void Circle::NumberofMembers(){
	int a = digraph.NumberofVertices();
	cout << "Number of the members of the circle:  " << a << endl;
	cout << endl;
}

void Circle::Edges(){
	int a = digraph.NumberofEdges();
	cout << "Number of friendships of the circle: " << a << endl;
	cout << endl;
}

void Circle::findVertex(){
	string name;
	cout << "Please enter the name you wanted to find in the circle" << endl;
	cin >> name;
	if(digraph.IsVertex(name)){
		cout << name << " is a member of the circle of friends" << endl;
		cout << endl;
		return;
	}
	cout << name << " is not a member of the circle of friends" << endl;
	cout << endl;
	return;
}

void Circle::findEdge(){
	ElementType element;
	string name1,name2;
	cout << "Please enter the names: " << endl;
	cin >> name1;
	cin >> name2;
	element = make_pair(name1,name2);	
	if(digraph.IsEdge(element)){
		cout << "Yes, the name1 has designated name2 as a friend" << endl;
		cout << endl;
		return;
	}
	cout << "No,the name1 has not designated name2 as a friend" << endl;
	cout << endl;
}

void Circle::findAnotherEdge(){
	ElementType element;
	string name1,name2;
	cout << "Please enter the names: " << endl;
	cin >> name1;
	cin >> name2;
	element = make_pair(name2,name1);	
	if(digraph.IsEdge(element)){
		cout << "Yes, the name1 has been designated by name2 as a friend" << endl;
		cout << endl;
		return;
	}
	cout << "No,the name1 has not been designated by name2 as a friend " << endl;
	cout << endl;
}

void Circle::remove(){
	ElementType element;
	string name1,name2;
	cout << "Please enter the names in order to remove edge between two people in the circle" << endl;
	cin >> name1;
	cin >> name2;
	element = make_pair(name1,name2);	
	if(digraph.removeEdge(element)){
		cout << "The edge removed in the circle" << endl;
		cout << endl;
		return;
	}
	cout << "The edge was not removed in the circle" << endl;
	cout << endl;
}

void Circle::countPredecessor(){
	string name;
	cout << "Enter a name: " << endl;
	cin >> name;
	int a = digraph.NumberofPredecessors(name);
	cout << "The number of people have designated this name as a friend: " << a << endl;
	cout << endl;
}

void Circle::Successor(){
	string name;
	cout << "Enter a name: " << endl;
	cin >> name;
	if(!digraph.IsVertex(name)){
		cout << "This member is not in the circle" << endl;
		return;
	}
	list<string> list1 = digraph.Successors(name);
	cout << name << "'s successors: " << endl;
	for(auto it:list1){
		cout << it << endl;
	}
	cout << endl;
}

