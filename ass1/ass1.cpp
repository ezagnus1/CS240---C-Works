#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int alpha=0;

int readFilePutIntoVector(vector<string>& v);
//input: a string vector
//output: if file does not open, it returns 0 but if file opens, it returns 1 and it can be controlled in main if number is equal to 0 it does not need to continue to the code.
//side effects: prompts user and read input for file.

int nonblankline(vector<string>& v);
//input: a vector of string
//output: returns number of non-blank lines in file
//side effects: none 

double FindTotalWord(vector<string>& v);
//input: a string vector
//output: returns the number of words in file
//side effects: none 

double avg_words(double word, int nonblank);
//input: one double variable and one int variable
//output: returns the average number of words per non blank line
//side effect: none

int WordControl(string b);
//input: a string
//output: a variable which returns 1 or 0 in order to control if string is a word or not.
//side effects:none

void AlphaChar(string a);
//input: a string
//output: none
//side effects: none

double avg_alpha(int alpha, double word);
//input: a string
//output: returns the average number of alphabetic characters per word
//side effects: none

int whitespace(string b); // this function controls if just there is a whitespace character in a line
//input: a string
//output: an int
//side effects: none




int main(){
	double avg1,avg2,word;
	int a,nonblank;
	vector<string> v;	
	
	a = readFilePutIntoVector(v); 
	if(a==1){
	nonblank = nonblankline(v);
	word = FindTotalWord(v);
	avg1 = avg_words(word,nonblank);
	avg2 = avg_alpha(alpha,word);
	
	cout << "The number of non-blank lines in the file = " << nonblank << endl; 
	cout << "The average number of words per non-blank line = " <<  avg1 << endl;
	cout << "The average number of alphabetic characters per word = " << avg2 << endl;
	}
	return 0;
} // main sonu


int readFilePutIntoVector(vector<string>& v){ // this function reads a file and non-blank lines of the file put into vector
	ifstream a;
	string filename;
	string rfile;
		
	cout << "Enter a filename: " << endl;
	cin >> filename;
	a.open(filename);//try to open file
	
	if (!a.is_open()) {
     		cout << filename << " couldn't be opened" << endl;
      		return 0;
   	}
	
	while(getline(a,rfile)){ // reads a line 
		int b = whitespace(rfile);
			if(b==1 && rfile!= ""){

			cout <<"lan: " << rfile <<endl;
			v.push_back(rfile);	
			}
	}
	a.close();//file closed																
	return 1;
	
} // ending of function


int nonblankline(vector<string>& v){
	int b = v.size();
	return b; // b is the number of non-blank lines
} // ending of function

double FindTotalWord(vector<string>& v){
	double word=0.0;
	int a;
	string c;
	for(int i=0;i<v.size();i++){
	
	string b = v.at(i);	
	istringstream inSS;
	inSS.str(b);
	while(inSS>>c){ // In this loop c reads a word of the string which is in istringstream. And this loop continues until end of the string
			
		a = WordControl(c); 

		if(a==1){
			
			word++;
		}
	}
	

}

	return word; // word is the number of the words in the file
}

double avg_words(double word, int nonblank){ // this function returns the average number of words per non-blank line
	return word/nonblank;
}



int WordControl(string b){ 
	for(int i=0; i<b.size();i++){
		if(isalpha(b.at(i))){
			
			AlphaChar(b);
			return 1;
		}
	}
	return 0;

}

void AlphaChar(string a){ // calculates the number of the alphabetic characters
	for(int i=0; i<a.size();i++){
		if(isalpha(a.at(i))){
			alpha++;
		}
	}

}

double avg_alpha(int alpha, double word){
	return alpha/word;
}

int whitespace(string b){
	for(int i=0; i<b.size();i++){
		if(isspace(b.at(i))){
			
		}
		else{
			return 1;
		}
	}
		return 0;

}
