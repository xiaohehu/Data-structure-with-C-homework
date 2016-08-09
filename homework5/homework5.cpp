#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Node {
	private: 
		string val; // user input provides value in collating sequence
		Node* lh; // pointer to left-hand descendant Node
		Node* rh; // pointer to right-hand descendant Node
		Node* parent; //pointer to parent Node or NULL if root Node
	public: 
		Node () { lh = rh = parent = NULL; val = ""; }
		void   putVal (string v) { val = v; }
		string getVal () { return val; }
		void   putLH (Node* x) { lh = x; }
		Node*  getLH () { return lh; }
		void   putRH (Node* x) { rh = x; }
		Node*  getRH () { return rh; }
		void   setParent(Node* x) {parent = x;}
		Node*  getParent() {return parent;}
};

class BST { // Container for Binary Search Tree
	private:
		Node* foundNode;
		string *names;
	private:
		void treeDisplay(Node*, int);
	public:
		BST ();
		Node* root;
		void createTree(string *arr, int size, Node* node);
		void createTree2(string *arr, int size);
		void treeDisplayRoot();
};
BST::BST () { // Default Constructor
	root = NULL; 
} 

void BST::treeDisplayRoot() {
	treeDisplay(root, 0);
}

void BST::treeDisplay(Node* ref, int depth) {
	// from Main & Savitch page 506
	cout << setw(4*depth) << ""; // indentation
	if (ref == NULL) {
		// reached a NULL reference in an interior node
		cout << "[NULL]" << endl;
	} 
	else 
	  if (ref->getLH() == NULL && ref->getRH() == NULL)
		{// a leaf
		 cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t)ref;
		 cout << " [leaf]" << endl;
		} 
	  else 
	    {// a nonleaf - interior node
		 if ( depth == 0 )
			cout << "            Root ";
		 cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t)ref << endl;
		 cout << "Left Child  " << depth+1;
		 treeDisplay(ref->getLH(), depth + 1);
		 cout << "Right Child " << depth+1;
		 treeDisplay(ref->getRH(), depth + 1);
		}
}

void BST::createTree2(string *arr, int size) {
	
}

void BST::createTree(string *arr, int size, Node* node) {
	int leftSize = size / 2;
	int rightSize = 0;
	if (size % 2) {
		rightSize = size / 2;
	}
	else {
		rightSize = size / 2 - 1;
	}
	
	// Base case of recursion
	// Only one node, compare value and insert
	if (size < 2) {
		string parentValue = node->getVal();
		string currentValue = *(arr + size / 2);
		Node *newNode = new Node();
		// If no root node, set value to root node and return
		if (root == NULL) {
			root = new Node ();
			root->putVal(currentValue);
			root->putLH(NULL);
			root->putRH(NULL);
			return;
		}
		
		// Set leaf node to the tree
		newNode->putVal(currentValue);
		newNode->setParent(node);
		// Put left side
		if (parentValue > currentValue) {
			node->putLH(newNode);
		}
		// Put right side
		if (parentValue < currentValue) {
			node->putRH(newNode);
		}
		return;
	}
	// If the tree's root node is not set yet, put the middle value to root
	if (root == NULL) {
		root = new Node ();
		string currentString = *(arr + size / 2);
		root->putVal(currentString);

		// Left side
		createTree(arr, leftSize, root);
		// Right side
		createTree(arr+size / 2 + 1, rightSize, root);
	}
	
	// Recursion part
	else {
		string parentValue = node->getVal();
		string currentValue = *(arr + size / 2);
		Node *newNode = new Node();
		newNode->putVal(currentValue);
		newNode->setParent(node);
		// Put left side
		if (parentValue > currentValue) {
			node->putLH(newNode);
		}
		// Put right side
		if (parentValue < currentValue) {
			node->putRH(newNode);
		}
		// Left side
		createTree(arr, leftSize, newNode);
		// Right side
		if (size != 2) {
			createTree(arr+size / 2 + 1, rightSize, newNode);
		}
	}
}

int main(int argc, char *argv[]) {
	// Init the sample data
	string names[13] = {
						"William", 
						"Ben", 
						"Edward", 
						"Kevin", 
						"Greer", 
						"Tim", 
						"Nate", 
						"John", 
						"Raziel", 
						"Rongjuan", 
						"Ofer", 
						"Steve",
						"Ian"
						};
	// Get the size of sample array
	int arraySize = sizeof(names)/sizeof(names[0]);
	
	// Sort the array
	sort(names,names + arraySize);
	
//	string temp;
//	for (int i = 0; i < arraySize; i++) {
//		for (int j = 0 ; j < arraySize - i; j++) {
//			if (names[j] > names[j+1])
//			{
//			 temp = names[j];
//			 names[j] = names[j+1];   
//			 names[j+1] = temp;    
//			}
//		}
//	}
	// Print out the ordered array
	cout << "The sorted array is: " << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << names[i] << endl;
	}
	cout << endl;
	
	// Create the balanced tree and display the tree
	BST *tree = new BST ();
	tree->createTree(names, arraySize, tree->root);
	tree->treeDisplayRoot();
}