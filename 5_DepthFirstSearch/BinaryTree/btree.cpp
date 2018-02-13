/* Question 5

Implement DFS (Depth-First Search) for a binary node
            2
          /   \
         7     5
       /  \       \
      2    6     9
          /  \     /
         5  11 4
print out the sequence of your DFS result

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


void btree::depthFirstSearch()
{
	stack<node *> s;
	s.push(this->root);

	while(!s.empty())
	{
		node * t = s.top();
		s.pop();
		cout<<t->key_value<<",";
		
		if(t->right != NULL){
			s.push(t->right);
			//cout<<t->right->key_value<<",";
		}
		
		if(t->left != NULL){
			s.push(t->left);
			//cout<<t->left->key_value<<", ";
		}
	}
	cout << endl;
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
