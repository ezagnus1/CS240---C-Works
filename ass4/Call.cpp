#include <cstdlib>
#include "Call.h"
#include <time.h>
using namespace std;

Call::Call(){
	arrive_time = 0;
	priority = rand()%10;
	priority = SetPriority(priority);
	answ_time = (rand()%6 + 3);
}


void Call::SetArrTime(int arrive_time){
	this->arrive_time = arrive_time; 
}

int Call::GetPriority(){
	return this->priority;
}

int Call::GetArrTime(){
	return this->arrive_time;
}

int Call::GetAnswTime(){
	return this->answ_time;
}

int Call::SetPriority(int priority){
	if(priority==0){
		return 1;
	}
	else if(priority==1 || priority==2 || priority==3){
		return 2;
	}
	else{
		return 3;
	}
}

bool Call::operator<=(const Call &a)const{
	if(this->priority <= a.priority){
		return true;
	}
	else{
		return false;
	}
	
}

bool Call::operator>(const Call &a)const{
	if(this->priority > a.priority){
		return true;
	}
	else{
		return false;
	}
}






