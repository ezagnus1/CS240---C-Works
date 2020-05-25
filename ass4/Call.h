#ifndef Call_
#define Call_

class Call{
	public:
		Call();
		//Constructor
		int SetPriority(int priority);
		//input: takes priority value and it determines which priority(1,2,or 3) will give  
  		// output: returns the value to set to the priority 
		void SetArrTime(int arrive_time);
		//input: the function sets arrive_time to a Call object
  		// output: none
		bool operator<=(const Call &a)const;
		//input: takes a Call object
  		// output: if the object's priority in the waitList is smaller than or equal to new object's priority return true, otherwise it returns false
		bool operator>(const Call &a)const;
		//input: takes a Call object
  		// output: if the object's priority in the waitList is greater than new object's priority return true, otherwise it returns false
		int GetPriority();
		//input: none
  		// output: returns the value of priority
		int GetArrTime();
		//input: none
  		// output: returns the value of arrive time
		int GetAnswTime();
		//input: none
  		// output: returns the value of answer time
		
	private:
		int priority;
		int arrive_time;
		int answ_time;
};

#endif
