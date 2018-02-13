/*
Question 5

Implement DFS (Depth-First Search) for a binary node
            2
          /   \
         7     5
       /  \       \
      2    6     9
          /  \     /
         5  11    4
print out the sequence of your DFS result

*/


#include<iostream>
#include<cstdlib>
#include<array>

#include "btree.h"

#include <iostream>

using namespace std;

int main(){
	
	btree *tree = new btree();
	
	tree->insert(2);
	tree->insert(7);
	tree->insert(5);
	tree->insert(2);
	tree->insert(6);
	tree->insert(9);
	tree->insert(5);
	tree->insert(11);
	tree->insert(4);
	
	
	
}







