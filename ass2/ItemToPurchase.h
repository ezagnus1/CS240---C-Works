#include <iostream>
using namespace std;
class ItemToPurchase{
	public:
		ItemToPurchase();
		ItemToPurchase(string name,double price,int quantity); 
		void SetName(string a);
                 //input: string
  		 //output: none
		void SetPrice(double a);
		 //input: double variable
   		//output: none
		void SetQuantity(int a);
		 //input: int variable
   		//output: none
		double CalculatePrice(int quantity, double price); 
		 //input: an int variable and one double variable 
   		//output: double variable
		string GetItemInfo()const;
		 //input:none
   		//output: string variable
		string GetItemInfo2()const;
		 //input: none
   		//output: a string variable
		double GetPrice();
		 //input: none
   		//output: double variable
		int GetQuantity();
		 //input: none
   		//output: int variable
		string GetName();
		 //input: none
   		//output: a string variable
		friend ostream& operator<< (ostream & out, const ItemToPurchase & f);

	private:
		string name;
		double price;
		int quantity;
};
