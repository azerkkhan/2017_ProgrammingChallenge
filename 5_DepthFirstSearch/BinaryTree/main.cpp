/*
Question 5

Implement DFS (Depth-First Search) for a binary node
            2
          /   \
         7     5
       /  \       \
      2    6       9
          /  \    /
         5   11  4
		 

print out the sequence of your DFS result

*/


#include<iostream>
#include<cstdlib>
#include<array>

#include "btree.h"

#include <iostream>

using namespace std;

int main(){
	
	/*Create a new binary tree.
	        2
          /   \
         7     5
       /  \       \
      2    6       9
          /  \    /
         5   11  4
	*/
	btree *tree = new btree();
	
	tree->root = new node();
	tree->root->key_value = 2;
	tree->root->left = new node();
	tree->root->right = new node();
	
	//Left side, 7,2,6,5,11.
	tree->root->left->key_value = 7;
	tree->root->left->left = new node();
	tree->root->left->left->key_value = 2;
	tree->root->left->left->left = NULL;
	tree->root->left->left->right = NULL;
	
	tree->root->left->right = new node();
	tree->root->left->right->key_value = 6;
	tree->root->left->right->left = new node();
	tree->root->left->right->left->key_value = 5;
	tree->root->left->right->left->left = NULL;
	tree->root->left->right->left->right = NULL;
	tree->root->left->right->right = new node();
	tree->root->left->right->right->key_value = 11;
	tree->root->left->right->right->left = NULL;
	tree->root->left->right->right->right = NULL;
	
	//Right side: 5,9,4
	tree->root->right->key_value = 5;
	tree->root->right->left = NULL;
	tree->root->right->right = new node();
	tree->root->right->right->key_value = 9;
	tree->root->right->right->right = NULL;
	tree->root->right->right->left = new node();
	tree->root->right->right->left->key_value = 4;
	tree->root->right->right->left->right = NULL;
	tree->root->right->right->left->left = NULL;
	
	
	
	
	
	//tree->inorder_print();
	
	tree->depthFirstSearch();
	
}


