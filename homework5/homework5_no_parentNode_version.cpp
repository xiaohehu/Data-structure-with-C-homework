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
		//void treeDisplay(Node*, int);
		Node* addNode(string);
	public:
		BST ();
		Node* createTree2(string *arr, int size);
		void treeDisplay(Node*, int);
};
BST::BST () { // Default Constructor

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

Node* BST::addNode (string v) {
	Node * x;
	if (x = new Node())
	{
		x->putVal(v);
		x->putLH(NULL);
		x->putRH(NULL);
	}
	return x;
}

Node* BST::createTree2(string *arr, int size) {
	if (size == 0)
	{
		return NULL;
	}
	
	int mid = size/2;
	Node *newNode = addNode(*(arr + mid));
	newNode->putLH(createTree2(arr, mid));
	if (size % 2) {
		newNode->putRH(createTree2(arr + mid + 1, mid));
	}
	else {
		newNode->putRH(createTree2(arr + mid + 1, mid - 1));
	}
	return newNode;
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
	
	// Print out the ordered array
	cout << "The sorted array is: " << endl;
	for (int i = 0; i < arraySize; i++) {
		cout << names[i] << endl;
	}
	cout << endl;
	
	// Create the balanced tree and display the tree
	BST *tree = new BST ();
	Node *haha;
	haha = tree->createTree2(names, arraySize);
	tree->treeDisplay(haha, 0);
}