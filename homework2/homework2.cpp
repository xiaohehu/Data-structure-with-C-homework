#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	// Init all varibles of the program
	int* array = NULL;
	int* temp = NULL;
	int count = 0;
	bool end = false;
	cout << endl;
	
	// While the iput is validate then do the loop to get the input number
	while (!cin.eof() && cin.good() && end == false)
	{
		// Use new[] operator to allocate a chunk of memory to get the input value 
		temp = new(int[count+1]);
		//Check the the memory heap is exhausted, if so terminate program
		if (temp == NULL) {
			cout << "Heap exhausted." << endl;  
			end = true;
		}
		else {  
			// Get the input value and put into temp array
			// Then delete array set temp's value to it
			cout << "Please input an int number or EOF to terminate" << endl;
			cin >> *(temp + count);  
			if (!cin.eof() && cin.good()) {  
				for (int i = 0; i < count; i++) 
					*(temp + i) = *(array + i);
				delete[] array;
				array = temp;
			}
			// If the input value is invalid, terminate the program
			else {
				if (!cin.eof()) {
					cout << "Invalid Input" << endl;
				}
				end = true;
			}
			// Add count number, because new element is added
			count++;
		}

	}
	// Jump out from loop value of count is 1 greater than the length of array
	count--;
	// Delete the temp array which is not used any more
	// To do so is preventing memory leak
	delete[] temp;
	
	// Go through the array and print all values out
	if (count > 0) {
		cout << "Input Array is: " << endl;
		for(int i = 0; i < count; i++) 
			cout << *(array + i) << " " << endl;
		}
	return 0;
}