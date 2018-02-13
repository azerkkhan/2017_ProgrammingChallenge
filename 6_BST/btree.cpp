/* Question 5
*/

#include "btree.h"
#include<stack>
#include<vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>


btree::btree()
{
  root=NULL;
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}


void btree::destroy_tree(node *leaf){
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}


void btree::insert(int key, node *leaf)
{
  if(key < leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

void btree::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->key_value << ",";
		inorder_print(leaf->right);
	}
}


void btree::lcaSearch(int a, int b)
{
	int i = 0, j = 0; //Variables used for for loops.
	vector<int> firstPath; //Stores path to first key's node.
	vector<int> secondPath; //Stores path to second key's node.
	vector<int> orderedFirstPath; //Stores the sorted first path.
	
	stack<node *> s;
	stack<node *> w;
	
	s.push(this->root);
	w.push(this->root);
	
	firstPath.push_back(root->key_value); //push the root key to the first path vector.
	secondPath.push_back(root->key_value); //push the root key to the second path vector.
	
	while(!s.empty()) //Stores the path to the first key into the firsPath vector.
	{
		node * t = s.top();
		s.pop();
		//firstPath.push_back(t->key_value);
		//cout<<t->key_value<<",";
		
		if(t->right != NULL && t->right->key_value != a){
			s.push(t->right);
			firstPath.push_back(t->right->key_value);
			//cout<<t->right->key_value<<",";
		}
			
		
		if(t->left != NULL && t->left->key_value != a){
			s.push(t->left);
			firstPath.push_back(t->left->key_value);
			//cout<<t->left->key_value<<", ";
		}
	}
	
	while(!w.empty()) //Stores the path to the first key into the firsPath vector.
	{
		node * x = w.top();
		w.pop();
		//cout<<x->key_value<<",";
		
		if(x->right != NULL && x->right->key_value != b){
			w.push(x->right);
			secondPath.push_back(x->right->key_value);
			//cout<<x->right->key_value<<",";
		}
			
		
		if(x->left != NULL && x->left->key_value != b){
			w.push(x->left);
			secondPath.push_back(x->left->key_value);
			//cout<<x->left->key_value<<", ";
		}
	}
	/*
	cout << endl;
	cout<<"First path contents: ";
	for(i = 0; i<firstPath.size(); i++){ //Prints first path contents.
		cout<<firstPath[i]<<", ";
		
	}
	
	cout<<endl<<"Second path contents: ";  //Prints second path contents.
	for(i = 0; i<secondPath.size(); i++){
		cout<<secondPath[i]<<", ";
		
	}
	*/
	
	//The following section finds the lowest common shared value of the two vectors.
	
	int low = 0, common =0;	
	//cout<<endl<<"First Path contents (ordered): ";
	//Find lowest common ancestor.
	
	
	firstPath = bubbleSort(firstPath);
	 // Verifying Bubble Sort Algorithm.
	/*
	for(int x = firstPath.size()-1; x>=0; x--){ //Prints the sorted vector contents.
		cout<<firstPath[x]<<", ";
	}
	*/
	
	
		
	//Performs LCA search.
	//i = firstPath.size()-1; 
	//cout<<"the first index is: "<<i<<endl;
	 //Low is the smallest number in the first path.
	//cout<<"the lowest value is : "<<low<<endl;
	
	for(i = firstPath.size()-1; i>=0; i--){
		low = firstPath[i];
		for(int j = 0; j<secondPath.size(); j++){
			if(low >= secondPath[j]){
				common = secondPath[j];
				cout<<common<<endl;
				return;
			}
		}
	}
		
	
	
}

void btree::breadthFirstSearch()
{
	queue<node *> s;
	// Initially mark all as not visited
    s.push(this->root);

	while(!s.empty())
	{
		node * t = s.front();
		s.pop();
		cout<<t->key_value<<", ";
		
		if(t->right != NULL){
			s.push(t->right);
			//cout<<t->right->key_value<<",";
		}
		
		if(t->left != NULL){
			s.push(t->left);
			//cout<<t->left->key_value<<", ";
		}
	}
}
vector<int> btree::bubbleSort(vector<int> v){
	int temp = 0;
	for(int i = 0; i < v.size()-1; i++)
    {
            if(v[i] < v[i+1])
            {
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
				i=0;
            }
    }
	return v;
}