Write a program that simulates the behavior of a call center.  This program will make use of a PriorityQueue.  You will need to write:
a PriorityQueue class - you can choose the implementation data structure.  If you choose a linked list, you need to provide a destructor, but do not need to provide a copy constructor or operator=.

a Call class - This class needs data members to store:
the time during the simulation at which the call arrived at the call center
its priority -  the priority is randomly computed (10% of calls have a priority of 1, 30%  have a priority of 2 and 60% have a priority of 3)
the time it will take to answer the call - the time is randomly computed and can be from 3 to 8 minutes
The Call class needs to overload the relational operator(s) used in your PriorityQueue class.  Call class objects need to be compared based on their priority values.
a CallCenter class based on the model of the call center discussed in class.  One of its data members will be:
        PriorityQueue waitList;   

The CallCenter will need methods to:
accept an arriving call
update the CallCenter
display simulation results
display current status of the simulation
a program that prompts the user for the system variables, creates a CallCenter object, conducts the simulation and displays the results of the simulation.  The system variables for the simulation are:
the simulation length, i.e. number of minutes during which calls will be accepted
arrival rate of calls, i.e. the probability of a call arriving during a given minute (between .1 and 1)
The basic algorithm for conducting the simulation is:
for each minute during which calls are being accepted
      determine if a new call has arrived
      if a new call has arrived
            create a Call object and send it to the CallCenter
      update the CallCenter
for each minute until all calls have been answered
      update the CallCenter
The results of the simulation to be displayed are:
total number of calls entered and answered
total time taken to answer all calls
average wait time for a call to be answered (the wait time for a call is the time at which the call was answered minus the time at which it arrived at the call center)
average wait time for calls with priority of 1, priority of 2 and priority of 3
In addition to the simulation results your program should, for every fifth minute of the simulation, display the following information:

the current simulation time
number of calls in the waiting list
number of calls completed

The .tar.gz file you submit should contain all the files needed to execute your program and a makefile.  
