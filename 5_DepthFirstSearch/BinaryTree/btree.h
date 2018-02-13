//Header File for BT.

#include <iostream>

using namespace std;

//Binary tree class
struct node
	{
	  int key_value;
	  node *left;
	  node *right;
	};

class btree{
    public:
	//Constructor
        btree(); 
	//Destructor	
        ~btree(); 
	
        void insert(int key);
        node *search(int key);
        void destroy_tree();
		void inorder_print();
		void depthFirstSearch();
		void breadthFirstSearch();
		node * root;

    private:
	//Member functions
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
		void inorder_print(node *leaf);
        
        
};
 