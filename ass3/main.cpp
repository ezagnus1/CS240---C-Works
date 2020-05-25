#include <iostream>
#include "Stack.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

string GetFilename();
//input: none
//output: returns a string
//side effects: prompts user to take a filename

void OpenFile(string filename);
//input: a string filename
//output: none
//side effects: if the file does not open, a message is written and if the file is empty, a message is written and it is called Postfix function in here.

void Postfix(string b);
//input: a string
//output: none
//side effects: This function is solving a given Postfix expression and it pushes the results to the stack. And it is called DisplayResults function in here.

int DisplayResults(string a,double num);
//input: a string and a double value
//output: int value
//side effects: it prints the results to the file.txt

int main(){
	string filename = "";
	filename = GetFilename();
	OpenFile(filename);
}

string GetFilename(){
	string a;
	cout << "Enter filename: " << endl;
	cin >> a;
	return a;
}

void OpenFile(string filename){
	
	vector<string> v;
	ifstream inFS;
	string b,a;
	inFS.open(filename);

	if(!inFS.is_open()){
		cout << "Could not open file " << filename << endl;
		return;
	}

	while(getline(inFS,b)){
		v.push_back(b);
		Postfix(b);
	}

	if(v.size()==0){
		cout << "This file is empty" << endl;
		return;
	}
	
	inFS.close();
	return;
}
void Postfix(string b){
	Stack a;
	istringstream inSS;
	double number1,number2;
	double number;
	string d;
	inSS.str(b);
	while(inSS >> d){
		if(isdigit(d.at(d.size()-1))){ // the control that if d is decimal number or operator.
			number = std::stod(d);
			a.Push(number);
		}

		else{
			number1 = a.Pop();
			number2 = a.Pop();

			if(d.at(0) == '+'){
				number1 = number2+number1;
				a.Push(number1);
				
			}
			else if(d.at(0) == '-'){
				number1 = number2-number1;
				a.Push(number1);
				
			}
			else if(d.at(0) == '*'){
				number1 = number2*number1;
				a.Push(number1);
				
			}
			else if(d.at(0) == '/'){
				number1 = number2/number1;
				a.Push(number1);
			}
		
		} // else ending

	} // while ending
	number1 = a.Pop();

	DisplayResults(b,number1);	
}// function ending


int DisplayResults(string a,double num){
	ofstream outFs;
	istringstream inSS;
	string b;
	outFs.open("file.txt",std::ios_base::app);
	if(!outFs.is_open()){
		cout << "Could not open file file.txt" << endl;
		return 1;
	}
	
	outFs << "The result of evaluating: ";
	
	inSS.str(a);
	while(inSS >> b){
 		outFs << b << " "; 
	}
	outFs << " is " << num << endl;
	outFs.close();
	return 0;
}

