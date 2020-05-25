#include <iostream>
#include "map.h"
using namespace std;

Map::Map(){
	size1 = 0;
	root = nullptr;
	heigh = 0;
	temp1 = 0;
}

Map::~Map(){
	cout << "Destructor called"<<endl;
	if(root==nullptr){
		return;
	}
	Postorder(root);
}

Map::Map(const Map& mapToCopy){
	cout << "Copy Constructor called"<<endl;
	root = nullptr;
	size1 = 0;
	heigh = 0;
	temp1 = 0;
	Node *temp;
	temp = mapToCopy.root;
	Preorder(temp);
	size1 = mapToCopy.size1;
	return;
}

Map Map :: operator=(const Map& object){
	cout << "Operator called"<<endl;
	if(root!=nullptr){
		Postorder(root);
	}
		root = nullptr;
		size1 = 0;
		heigh = 0;
		temp1 = 0;
		Node *temp = object.root;
		Preorder(temp);
		size1 = object.size1;
		return object;
	
}

bool Map::empty()const{
	if(size1==0){
		return true;
	}
	else{
		return false;
	}
}

int Map::size()const{
	return size1;
}

bool Map::add(ElementType element){
	if(find(element.first)){
		delete element.second;
		return false;
	}

	if(root==nullptr){
		Node *ptr = new Node();
		ptr->data = element;
		ptr->right = nullptr;
		ptr->left = nullptr;
		root = ptr;	
		size1++;
		return true;
	}

	else{
		Node *ptr = new Node();
		Node *current;
		current = root;
		while(current != nullptr){
			if(element.first < current->data.first){
				if(current->left == nullptr){
					ptr->data = element;
					ptr->right = nullptr;
					ptr->left = nullptr;
					current->left = ptr;
					current = nullptr;
					size1++;
					return true;
				}
				else{
					current = current->left;
				}
			}

			else{
				if(current->right == nullptr){
					ptr->data = element;
					ptr->right = nullptr;
					ptr->left = nullptr;
					current->right = ptr;
					current = nullptr;
					size1++;
					return true;
				}
				else{
					current = current->right;
				}
			}
			
		} // while ending 
	}// else ending
}


bool Map::find(KeyType key) const{
	if(root == nullptr){
		return false;
	}
	else{
		Node *current = root;
		while(current != nullptr){
			if(current->data.first == key){
				return true;
			}
			else{
				if(key < current->data.first){
					current = current->left;
				}
				else{
					current = current->right;
				}
			}
		}
	}
	return false;
}

ValueType Map::retrieve(KeyType key) const{
	if(root == nullptr){
		return nullptr;
	}	
	else{
		Node *current = root;
		while(current != nullptr){
			if(current->data.first == key){
				return current->data.second;
			}
			else{
				if(key < current->data.first){
					current = current->left;
				}
				else{
					current = current->right;
				}
			}
		}
	}
	return nullptr;
	
}


bool Map::remove(KeyType key){
	if(root == nullptr){
		return false;
	}
	else{
		Node *current = root;
		Node *temp = nullptr;
		while(current!=nullptr){
			if(current->data.first == key){
				if(current->left == nullptr && current->right == nullptr){
					if(current==root){
						delete current->data.second;
						delete current;
						root = nullptr;
						size1--;
						return true;
					}
					else if(temp->left == current){
						delete current->data.second;
						delete current;
						temp->left = nullptr;
						size1--;
						return true;
					}
					else{
						delete current->data.second;
						delete current;
						temp->right = nullptr;
						size1--;
						return true;
					}
				} // inner if ending

				else if(current->left!=nullptr && current->right == nullptr){
					if(current == root){
						root = current->left;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
					else if(temp->left == current){
						temp->left = current->left;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
					else{
						temp->right = current->left;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
				} // else if ending
				else if(current->left == nullptr && current->right != nullptr){
					if(current == root){
						root = current->right;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
					else if(temp->left == current){
						temp->left = current->right;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
					else{
						temp->right = current->right;
						delete current->data.second;
						delete current;
						size1--;
						return true;
					}
				} // else if ending
				

				else{
					int a = 0;
					Node *suc =  current->right;
					Node *temporary = current->right;
					while(suc->left!=nullptr){
						if(a!=0){
							temporary = temporary->left;
						}
						suc = suc->left;
						a++;
					}
					current->data.first = suc->data.first;
					*(current->data.second) = *(suc->data.second);
					temporary->left = suc->right;
					if(a==0){
						current->right = nullptr;
					}
					delete suc->data.second;
					delete suc;
					size1--;
					return true;					
				} // else ending
				
				

			} // outer if ending

			else if(current->data.first < key){
				temp = current;
				current = current->right;
			}
			else{
				temp = current;
				current = current->left;
			}
		}// while ending
		
		return false;

	}// else ending

} // function ending

void Map::displayAll(){
	if(root == nullptr){
		return;
	}
	else{
		Inorder(root);
	}
	
}

int Map::height(){
	int h;
	CalculateHeight(root);
	heigh--;
	h = heigh;
	heigh = 0;
	temp1 = 0;
	return h;
}

void Map::Inorder(Node *temp){
	if(temp==nullptr){	
		return;
	}
	Inorder(temp->left);
	cout << "The key is " << temp->data.first << endl;
	Inorder(temp->right);
}


void Map::Postorder(Node *temp){
	if(temp==nullptr){
		return;
	}
	Postorder(temp->left);
	Postorder(temp->right);
	delete temp->data.second;
	delete temp;
}

void Map::Preorder(Node *temp){
	if(temp!=nullptr){
		KeyType key = (temp->data).first;
		ValueType value = new string(*(temp->data).second);
		ElementType element = make_pair(key,value);
		add(element);
	}
	else{
		return;
	}
	Preorder(temp->left);
	Preorder(temp->right);
}

void Map::CalculateHeight(Node *temp){
	if(temp==nullptr){
		return;
	}
	temp1++;
	if(heigh<temp1){
		heigh++;
	}
	CalculateHeight(temp->left);	
	CalculateHeight(temp->right);	
	temp1--;
}
