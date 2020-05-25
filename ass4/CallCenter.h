#ifndef Call_Center_
#define Call_Center_

#include "PriorityQueue.h"

using namespace std;

class CallCenter{
	
	public:
		CallCenter();
		//Constructor
		void AcceptCall(Call& object);
		// input: takes a Call object , and this object is sent to insert to the waitlist.
  		// output: none
		void UpdateCallCenter(int b);
		// input: b represents Simulation time ,and helps us which simulation time we are in. 
 		// output: none	
		void DisplayResults();
		// input: none
   		// output: none
		// At the end of the simulation , it is displayed results
		void DisplayCurrStatus(int s_time);
		// input: s_time represents which simulation time we are in.
   		// output: none
		// It displays every fifth minute of the simulation
		int GetTotal();
		// input: none
   		// output: if the simulation length has done , returns the time which until Call objects has done in the waitList.
		void Calculate();
		// input: none
   		// output: none
		// After the simulation has done, it calculates some CallCenter data members. 
		
	private:
		int total;
		int comp;
		PriorityQueue waitList;
		int entered_call;
		int answered_call;
		int totansw_time;
		double wait_time;
		Call obj;
		int complete_call;
		double avg_wait;
		int p1,p2,p3;
		double avg_p1,avg_p2,avg_p3;
		double tot_wait_time;
};	

#endif
