#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

string readFileName();
//input: none
//output: string
//side effects: prompts user and read input for file.
void readIPaddresses(set<string>& address);
//input: set<string>
//output: none
//side effects: read Ip addresses and calculate the number of known spammer IP addresses.
void readSpammers(set<string>& address);
//input: set<string>
//output: none
//side effects: read Ip addresses in check file , compare check file and spammers file, and calculate the number of good and bad IP addresses found.
void RemoveSpammers(set<string>& address);
//input: set<string>
//output: none
//side effects: reads Ip addresses in remove file , compares remove file and set, and calculates the number of IP addresses removed from the set of known spammer.

int main(){
	clock_t ticks;
	ticks = clock();
	set<string> address;
	readIPaddresses(address);
	readSpammers(address);
	RemoveSpammers(address);
	ticks = clock() - ticks;
	float seconds = (float) ticks / CLOCKS_PER_SEC;
	cout << "The amount of time taken to run the program : " << seconds << endl;
}

string readFileName(){
	string filename;
	cin >> filename;
	return filename;
}

void readIPaddresses(set<string>& address){
	int a=0;
	string line,filename;
	ifstream file;
	cout << "Enter the spammers file: "<< endl;
	filename = readFileName();
	file.open(filename);
	
	if(!file.is_open()){
		cout << "Could not open this file" << endl;
      		return; 
	}
	
	while(getline(file,line)){
		a++;
		address.emplace(line);
	}
	cout << "The number of known spammer IP addresses is : " << a << endl; 
} // ending function

void readSpammers(set<string>& address){
	int good=0,bad=0;
	string line,filename;
	ifstream file;
	cout << "Enter the checking file: "<< endl;
	filename = readFileName();
	file.open(filename);
	if(!file.is_open()){
		cout << "Could not open this file" << endl;
      		return; 
	}
	
	while(getline(file,line)){
		if(address.count(line) == 1){
			bad++;
		}
		else{
			good++;
		}
	}
	cout << "The number of good IP addresses found : " << good << endl;
	cout << "The number of bad IP addresses found : " << bad << endl;
}

void RemoveSpammers(set<string>& address){
	int a = 0;
	string line,filename;
	ifstream file;
	cout << "Enter the removing file: "<< endl;
	filename = readFileName();
	file.open(filename);
	if(!file.is_open()){
		cout << "Could not open this file" << endl;
      		return; 
	}
	
	while(getline(file,line)){
		if(address.erase(line) == 1){
			a++;
		}
	}
	cout << "The number of IP addresses removed from the set of known spammers : " << a << endl;
}
