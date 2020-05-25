#include <iostream>
#include <cstdlib>
#include <time.h>
#include "CallCenter.h"
using namespace std;

void GetVariables();
//input: none
//output: none
//side effects: prompts user to take system variables(the simulation length, and arrival rate of calls)
void Simulation(int minute, double arrival_rate);
//input: minute is simulation time , and arrival_rate represents arrival rate of calls
//output: none
//side effects: Simulation cases happen in this function.

int main(){
	srand(time(NULL));
	GetVariables();
	return 0;
}

void GetVariables(){
	int minute;
	double arrival_rate;
	cout << "Enter the simulation length" << endl;
	cin >> minute;
	cout << "Enter arrival rate of calls between 0.1 - 1" << endl;
	cin >> arrival_rate;
	Simulation(minute,arrival_rate);
	
}

void Simulation(int minute, double arrival_rate){
	CallCenter obj1;	
	int a,b,count=0,d=0; 
	a = arrival_rate * 10; 
	while(minute > 0){
		b = rand()%10+1;
		if(a >= b){ //  this line controls if Call object will exist or not. 
			Call z; // z is call object
			z.SetArrTime(count);
			obj1.AcceptCall(z);
			d++; // I am using d because if it never enters to inside this function, it means that any Call object never be existed during the simulation. 
			     // With this variable, if a Call object never be formed, a message is printed out to the screen. 
		}
		obj1.UpdateCallCenter(count);
		minute--;
		count++;
		
		if((count)%5 == 0 && count!=0){ // this line controls to display every fifth minute of the simulation
			obj1.DisplayCurrStatus(count);
			cout << endl;
		}
		
	}// while ending
	
	while(count < obj1.GetTotal()){
		obj1.UpdateCallCenter(count);
		count++;
		if((count)%5 == 0 && count!=0){
			obj1.DisplayCurrStatus(count);
			cout << endl;
		}
	}

		if(d!=0){
			obj1.Calculate();
		}

			obj1.DisplayResults();	

		if(d==0){
			cout << "Any calls never come to the CallCenter" << endl;
		}
}

