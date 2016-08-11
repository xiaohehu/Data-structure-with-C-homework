// Author: John Maslanka
// Program bintree3B2.cpp -- create a binary tree
// Date:   23-Jul-2002
// Installation: Home PC with MicroSoft Visual C++ V6.0

#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <string>
using namespace std;
/*
	(1)
	===============================
	No changes for Node class
	===============================
*/
class Node {
	private: 
		string val; // current value in collating sequence
		Node* lh; // pointer to left-hand descendant Node
		Node* rh; // pointer to right-hand descendant Node

	public: 
		Node () { lh = rh = NULL; val = ""; }  // Node () {}
		void   putVal (string v) { val = v; }
		string getVal ()	    { return val; }
		void   putLH (Node* x)   { lh = x; }
		Node*  getLH ()	    { return lh; }
		void   putRH (Node* x)   { rh = x; }
		Node*  getRH ()	    { return rh; }
		void	write (Node*);
};
		 
void Node::write (Node* n) { // Diagnostic to display a node of a Binary Tree
	cout << "Value " << val << " in Node at " << (int)(size_t)n;
	cout << "\t Its LH child "  << (int)(size_t)(lh) << "\t Its RH child " 
				  << (int)(size_t)(rh) << endl;
		}

class BT {  // Container class - does most of the work

private:
	Node* root;
	Node* tree;
private:
	Node* addNode (Node*, string); 
	Node* findInsertion (Node*, string); 
	void inOrder (Node*); 
    void locate (Node*, string); 
	void treePrint(Node*, int); 
public:
	BT ();
	Node* getRefToRoot();
	void addRootNode (string);
	void inOrderTraverse ();
    void locateRoot (string);
	void treePrintWrapper();
/*
	(2)
	===============================
	Create a function to get the root node of subtree
	By using the input value
	===============================
*/	
	Node* search(string);
	
/*
	(2)
	===============================
	Create a function to get subtree's population
	===============================
*/		
	int getSubtreePopulation(Node*);
};

Node* BT::getRefToRoot() 
	{return root;}

BT::BT () { root = tree = NULL; }    // BT::BT () {}

void BT::addRootNode (string v)
	{ if (root == NULL)
		{root = tree = addNode (tree, v);
	 //	 cout << "ptr to root " << root << endl;
        }
	  else
		{ tree = root;
		  tree = findInsertion (tree, v);
		} }

Node* BT::findInsertion (Node* tree, string v)
{ string x;
  x = tree -> getVal();
  if ( x == v) 
  {
	cout << "Duplicate user values not allowed in this tree" << endl;
	return tree;
  } else {
	if ( v < x ) 
		if( tree -> getLH () !=NULL )
			{ tree = findInsertion (tree -> getLH(), v);
			   return tree; 
			}
		  else
			{ Node* temp = NULL;
			  temp = addNode (temp, v);
			  tree ->putLH(temp); }
	  else // if ( v > x )
		  if (tree -> getRH () !=NULL )
		    { tree = findInsertion (tree -> getRH(), v);
			   return tree;	
			}
		  else
			{ Node* temp = NULL;
			  temp = addNode (temp, v);
			  tree ->putRH(temp); }
	  }
	  return tree; 
}
Node* BT::addNode (Node* x, string v)
	{ if (x = new Node())
		{ x->putVal (v);
		  x->putLH(NULL);
		  x->putRH(NULL); }
	  return x; }
void BT::locateRoot (string v) {
    if ( root == NULL )
       cout << "Tree is empty" << endl;
    else
       locate ( root, v );
    }
void BT::locate (Node* y, string v) {  // Bug mentioned by Dan Glade
    string x;
    x = y -> getVal ();
    if ( v == x ){ 
		cout << "Value " << v << " is in Node at address " << (int)(size_t)y << endl;
	}
    else if ( v <= x )
        if ( y -> getLH() != NULL )
            locate (y-> getLH(), v);
        else
            cout << "Value not in tree" << endl;
    else // if ( v > x )
        if ( y -> getRH() != NULL )
            locate ( y-> getRH(), v );
        else
            cout << "Value not in tree" << endl;
	
}


/*
	(2)
	===============================
	Complete search function
	===============================
*/
Node* BT::search(string x)
{
	Node *temp = root;
// Loop through the tree, return the node when node's value matches the input argument "x"
	while (temp != NULL)
	{
		if (temp->getVal() == x){
			return temp;
		}

		if (x > temp->getVal())
			temp = temp->getRH();
		else                  //  <--- Put this 'else' here
		if (x < temp->getVal())
			temp = temp->getLH();
	}
	if (temp == NULL)
		cout << "Value not in tree" << endl;
		return NULL;
}


/*
	(2)
	===============================
	getSubtreePopulation function code
	1. The inintial sum is 1 (if input node is a leaf node, the subtree size is only itself)
	2. Check if the input node has both left and right hand, then add both of their subtree's population
	3. If the node only has one node, then use the method to get that node's subtree's population 
	===============================
*/	
int BT::getSubtreePopulation(Node* node) {
	if (node == NULL) {
		return 0;
	}
	int sum = 1;
	if (node->getLH() != NULL && node->getRH() != NULL) {
		sum = sum + getSubtreePopulation(node->getLH());
		sum = sum + getSubtreePopulation(node->getRH());
	}
	if (node->getLH() == NULL && node->getRH() != NULL) {
		sum = sum + getSubtreePopulation(node->getRH());
	}
	if (node->getLH() != NULL && node->getRH() == NULL) {
		sum = sum + getSubtreePopulation(node->getLH());
	}
	if (node->getLH() == NULL && node->getRH() == NULL) {
		return sum;
	}
	return sum;
}

void BT::inOrderTraverse ()
{ //tree = root;
	  cout << endl;
	  inOrder (root); 
}
void BT::inOrder (Node* n)
{ if (n != NULL) {
	  inOrder (n->getLH());
	  n->write (n);
	  // cout << endl;
	  inOrder (n->getRH());
}
	return;
}

void BT::treePrint(Node* ref, int depth) {
  // from Main & Savitch page 506
  cout << setw(4*depth) << ""; // indentation
  if (ref == NULL) {
    // reached a NULL reference in an interior node
    cout << "[NULL]" << endl;
  } else if (ref->getLH() == NULL && ref->getRH() == NULL) {
    // a leaf
    cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t)root;
    cout << " [leaf]" << endl;
  } else {
    // a nonleaf - interior node
    cout << "Value " << ref->getVal() << " at Ref " << (int)(size_t)ref << endl;
	cout << "LH" << depth+1;
    treePrint(ref->getLH(), depth + 1);
	cout << "RH" << depth+1;
    treePrint(ref->getRH(), depth + 1);
  }
}


int main () {
string x;
char op = ' ';
BT TREE;
cout << "To create your Binary tree, use the menu below." << endl << endl;
while (!cin.eof() && op != 'E' && op != 'e')  // build a binary tree in this while loop
{cout << "Enter your operation using the Capital letter in your selection." << endl; 
/*
	(3)
	===============================
	Add one more option here to the the population of the subtree 
	===============================
*/
   cout << "(A)dd a node, display (T)ree, (S)how lists, display a (N)ode, (P)opulation of subtree,(E)xit: ";
   cin >> op;
   if (!cin.eof () && op != 'E' && op != 'e')
	switch (op)
	{case 'A': case 'a':
		{ cout << "Enter your string: ";
		  cin >> x;
		  if (!cin.eof())
			 TREE.addRootNode (x);
		  break;
		}
	case 'S': case 's':
		{if ( TREE.getRefToRoot ())
			{ cout << endl << "In-OrderTree Traversal:";
			  TREE.inOrderTraverse ();
		      cout << endl;
			}
		break;
		}
	case 'T': case 't':
		{if (TREE.getRefToRoot ())
			{ cout << endl << "Display Tree:" << endl;
			  //TREE.treePrintWrapper ();
		      cout << endl;
			}
		break;
		}
	case 'N': case 'n':
        	{ cout << endl << "Enter User value of Node to Display: ";
          	  cin >> x;
          	  if (!cin.eof())
			  if (TREE.getRefToRoot ())
					TREE.locateRoot ( x );
			  else
					cout << endl << "Tree is empty. No entries found.";
		  cout << endl;
		  break;
		}
		
/*
	(3)
	===============================
	In case user input "P" or "p", do the subtree calculation 
	===============================
*/
	case 'P': case 'p':
		{
			cout << endl << "Enter User value of root node of the subtree you want: ";
			cin >> x;
		// Check if the tree is empty or not
			if (TREE.getRefToRoot ()) {
				int sum = 0;
				Node* subRoot;
		// Using search(string x) function fide the root node of the subtree
		// If the node is not found then exit
				subRoot = TREE.search(x);
				if (subRoot != NULL) {
				/*	
					Pass the root node of subtree to method "getSubtreePopulation(Node*)" 
					to get the population of subtree
				*/
					sum = TREE.getSubtreePopulation(subRoot);
					cout << "The population of subtree is: " << sum << endl;
				}
			}
			else {
				cout << endl << "Tree is empty. No entries found.";
			}
			  cout << endl;
			break;
		}
	case 'E': case 'e':
		{ break;
		}
	default:
		{ cout << "Invalid operation. Try again!" << endl;
		  break;
		}
	  }
	}
    return EXIT_SUCCESS;
}
