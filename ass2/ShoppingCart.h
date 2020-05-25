#ifndef Shopping_Cart_
#define Shopping_Cart_

#include "LinkedList.h"

class ShoppingCart{ 
                 
public:
   ShoppingCart();
   void DisplayPosition(int pos)const; 
   //input: pos is an input to be showed item in this position
   //output: none
	//side effects: promt the item at position
   void DisplayAllitem() const; 
    //input: none
   //output: none
	//side effects: promt the all items
   void DisplayCostPosition(int pos) const;
    //input: pos is an input to be showed the cost of the item in this position
   //output: none
	//side effects: promt the cost of item at position
   void DisplayCostItems() const; 
    //input: none
   //output: none
	//side effects: promt total cost of items
   void DisplayNumberOfItem() const;
    //input: none
   //output: none
	//side effects: promt the number of items
   bool Insert(int newPos, const ItemType & newEntry);
    // input: element to be added to the list and position at
   //        which to add it 
   // output: newEntry is 
   //         at newPos and true is returned; else false is
   //         returned
	//side effects: promt the if item added
   bool Remove(int pos);  
   // input: pos is position of element to be removed
   // output: the element at pos is
   //         removed, and true is returned; else false is
   //         returned 
	//side effects: promt the if item removed
   ItemType Retrieve(int position) const;
   // input: position of element to be returned
   // output: element at position is returned
  	//side effects: promt the item at position
   bool Append(const ItemType & newEntry);
   // input: element to be added to the end of the list
   // output: if newEntry was appended to the list true is
   //         returned; else false is returned
	//side effects: promt the if item added

private:
	LinkedList cart;
};

#endif
