#include <algorithm>
#include "digraph.h"
using namespace std;

Digraph::Digraph(){
	
}

void Digraph::CreateDigraph(){
	countEdges = 0;
}

bool Digraph::addVertex(string element){
	auto it = find(vertex.begin(),vertex.end(),element);
	if(it==vertex.end()){
		vertex.push_back(element);
		Node *temp = new Node();
		v.push_back(*temp);
		return true;
	}
	return false;
	
}

bool Digraph::addEdge(ElementType element){
	auto it = find(vertex.begin(),vertex.end(),element.first);
	auto it2 = find(vertex.begin(),vertex.end(),element.second);
	if(*(it)!=element.first || *(it2)!=element.second){
		return false;
	}
	if(IsEdge(element)){
		return false;
	}
	int index1 = it - vertex.begin();
	int index2 = it2 - vertex.begin();
	
	(v.at(index1).successors).push_back(element.second);
	(v.at(index2).predecessors).push_back(element.first);
	countEdges++;
	return true;
	
}

bool Digraph::removeEdge(ElementType element){
	if(!IsEdge(element)){
		return false;
	}
	
	auto it = find(vertex.begin(),vertex.end(),element.first);
	auto it2 = find(vertex.begin(),vertex.end(),element.second);

	int index1 = it - vertex.begin();
	int index2 = it2 - vertex.begin();
	v.at(index1).successors.remove(element.second);
	v.at(index2).successors.remove(element.first);
	countEdges--;
	return true;
		
}

bool Digraph::IsEdge(ElementType element){
	auto it = find(vertex.begin(),vertex.end(),element.first);
	auto it3 = find(vertex.begin(),vertex.end(),element.second);
	if(*it != element.first || *it3 != element.second){
		return false;
	}
	int index1 = it - vertex.begin();
	auto it2 = find(v.at(index1).successors.begin(),v.at(index1).successors.end(),element.second);
	if(*it2!=element.second){
		return false;
	}
	return true;
}

bool Digraph::IsVertex(string element){
	auto it = find(vertex.begin(),vertex.end(),element);
	if(*it == element){
		return true;
	} 
	return false;
}

int Digraph::NumberofVertices(){
	return vertex.size();
}

int Digraph::NumberofEdges(){
	return countEdges;
}

vector<string>& Digraph::Vertices(){
	return vertex;
}

list<string>& Digraph::Successors(string element){
		auto it = find(vertex.begin(),vertex.end(),element);
		int index1 = it - vertex.begin();
		return (v.at(index1).successors);
}

int Digraph::NumberofPredecessors(string element){
	auto it = find(vertex.begin(),vertex.end(),element);
	int index1 = it - vertex.begin();
	return (v.at(index1).predecessors.size());
}
