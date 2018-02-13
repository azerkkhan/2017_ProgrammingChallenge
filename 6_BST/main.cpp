/*
Question 5

Find the least common ancestor (LCA) of two nodes in a binary search tree
Please read the key vector {500,300,600,550,700,750,200,150,250,350,800}
Pick up two random keys and show LCA

*/


#include<iostream>
#include<cstdlib>
#include<array>
#include<vector>

#include "btree.h"

#include <iostream>

using namespace std;

int main(){
	
	btree *tree = new btree(); //Create a new binary tree.
	vector<int> key = {500,300,600,550,700,750,200,150,250,350,800}; //List of vector keys.
	
	for(int i = 0; i<key.size(); i++){
		tree->insert(key[i]);
	}
	
	//tree->findLCA(500, 300);
	//cout<<"Inorder print: ";
	//tree->inorder_print(); //Prints in order.
	
    cout<<"Finding the Lowest common ancestor: "<<endl;	
	cout<<"The lowest Common Ancestor of 600 and 150 is: ";
	tree->lcaSearch(600,150); //Performs search to find LCA.
	cout<<"The lowest Common Ancestor of 250 and 150 is: ";
	tree->lcaSearch(250,150); //Performs search to find LCA.
	cout<<"The lowest Common Ancestor of 300 and 500 is: ";
	tree->lcaSearch(300,500); //Performs search to find LCA.
	cout<<"The lowest Common Ancestor of 600 and 500 is: ";
	tree->lcaSearch(600,500); //Performs search to find LCA.
	
	
}


