/*
READ ME:
	
	1. Create a Class names "HashTable" 
	
	2. Create 2 functions "makeHashTable" and "printHashTable"
	
	3. Make all the varibles as private parameter of the class
	
	4. Create Container class
	
	5. In the container class create instance of "HashTable class" and also call those 2 functions
	
	6. In main(), create an instance of Container to create the hash table.
*/

#include <iostream>
#include <string>
using namespace std;
#define MAX 23 

// Create the HashTable class and also 2 public function to create & print the table
class HashTable {
	private:
		
	// All parameters here are using in the 2 functions and they are all private
		bool full;
		char inputLine[80];
		int hashValue, modHash, i;
		string name [MAX];
		int firstHash [MAX];
		bool occupied [MAX];
	public:
		HashTable();
		void makeHashTable();
		void printHashTable();
};
HashTable::HashTable(){

}

void HashTable::makeHashTable() {
	while (!cin.eof() && full == false) 
		{ 
			// test for EOF, for hash table not full
			cout <<"Please enter a string of characters followed by <Enter>." << endl 
				<< "Terminate by entering EOF (control-z on keyboard in Windows." << endl;
			cin.getline(inputLine, 80); 
			if (!cin.eof()) 
			{
				hashValue = 0;  // calculate initial hash value
				
				for (i = 0; i < strlen (inputLine); i++)
				{  
					hashValue += (int) inputLine[i];      
				}
				
				modHash = hashValue % MAX;	// test initial hash value for available //  array entry
				if (occupied[modHash] == false) 
				{ 
					name[modHash] = inputLine;	
					firstHash[modHash] = modHash;
					occupied [modHash] = true;
					cout << "Your input line " << inputLine << " hashes to "
						<< modHash << endl;
				}
				else   // test failed, look for alternate location in array
				{ 
					cout << "Hash collision! We need to find an open table entry." << endl;
					bool found = false;  // declare binary state variable "found": 
							     // false means an available array position 
							     // not found, true means it is found.
					for (i = 0; i < MAX && found == false && full == false; i++)
					{
						// test found == false, need to stop execution of this 
						// loop when an available array position is found
						if (occupied[i] == false)
						{ 
							// test if selected hash
	   						// table element is occupied 
							name[i] = inputLine;											
							firstHash[i] = modHash;
							occupied [i] = true;
							cout << "Your input line " << inputLine 
								<< " hashes to " << i << endl;
							found = true; // Set array position found
						}
						else
							if (i >= MAX-1) { 
								cout << "Sorry! Table is full!"  <<" We cannot place your entry." 
									<< endl << endl;
								full = true;  // set state flag to say 
								//  hash array to full
							}
					}
				}
			}
		}
}

void HashTable::printHashTable() {
	for (i = 0; i < MAX; i++) { // finally, list members of hash table
		if (occupied[i] == true) 
		{
			cout << " Position in table is " << i;
			cout << " Hashed to " << firstHash[i];
			cout << ".\tString is " << name[i] << endl;
		}
	}
}

// Create the container class and call 2 functions of HashTable class
class Container {
	public:
		void createAndPrintHashTable();
};

void Container::createAndPrintHashTable() {
	HashTable hash;
	hash.makeHashTable();
	hash.printHashTable();
}
int main () {
	
// In main(), only create the instance of container class and run function "createAndPrintHashTable()"
	Container container;
	container.createAndPrintHashTable();
	return 0;
}