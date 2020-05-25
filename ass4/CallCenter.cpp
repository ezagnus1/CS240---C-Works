#include <iostream>
#include "CallCenter.h"
using namespace std;

CallCenter::CallCenter(){
	comp = 0;
	entered_call = 0;
	answered_call = 0;
	totansw_time=0;
	wait_time=0.0;
	complete_call = 0;
	avg_wait = 0.0;
	p1=0;
	p2=0;
	p3=0;
	avg_p1=0.0;
	avg_p2=0.0;
	avg_p3=0.0;
	total = 0;
	tot_wait_time = 0.0;
}

void CallCenter::AcceptCall(Call& object){
	total += object.GetAnswTime();
	waitList.enqueue(object);
	entered_call++;
	return;
}

void CallCenter::UpdateCallCenter(int b){
	int arr,answ;
	if(waitList.GetLength() == 0 && comp == 0){
		return;
	}
	else if(waitList.GetLength()!=0 && comp == 0){
		answered_call++;
		obj = waitList.front();
		comp = obj.GetAnswTime();
		arr = obj.GetArrTime();
		answ = b;
		wait_time = b-arr;
		tot_wait_time += wait_time;
		
		if(obj.GetPriority() == 1){
			p1++;
			avg_p1+= wait_time; 
		}

		if(obj.GetPriority() == 2){
			p2++;
			avg_p2+= wait_time; 	
		}

		if(obj.GetPriority() == 3){
			p3++;
			avg_p3+= wait_time; 		
		}

		totansw_time+=comp;
		waitList.dequeue();
		comp--;
		return;
	}
	else if(comp != 0){
		comp--;
		if(comp == 0){
			complete_call++;
			return;
		}
		return;
		
	} // inner else if ending
}// else if ending

void CallCenter::Calculate(){
		avg_wait = tot_wait_time / entered_call;
		if(p1!=0){
			avg_p1 = avg_p1 / p1;
		}
		if(p2 != 0){
			avg_p2 = avg_p2 / p2;
		}
		if(p3 != 0){
			avg_p3 = avg_p3 / p3;
		}
}

void CallCenter::DisplayResults(){
	cout << "Total number of calls entered and answered: " << entered_call << endl;
	cout << "Total time taken to answer all calls: " << totansw_time << endl;
	cout << "Average wait time for a call to be answered: " << avg_wait << endl;
	cout << "Average wait time for calls with priority of 1: " << avg_p1 << endl;
	cout << "Average wait time for calls with priority of 2: " << avg_p2 << endl;
	cout << "Average wait time for calls with priority of 3: " << avg_p3 << endl;
	
}

void CallCenter::DisplayCurrStatus(int s_time){
	cout << "Simulation time is: " << s_time << endl;
	cout << "Number of calls in the waiting list: " << waitList.GetLength() << endl;
	cout << "Number of calls completed: " << complete_call << endl;
}

int CallCenter::GetTotal(){
	return total;
}
