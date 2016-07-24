#include <iostream>

using namespace std;

bool isValueInArray(int val, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (val == arr[i])
            return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
	string inputValue;
	char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	char operators[4] = {'+', '-', '*', '/'};
	char validValues[14] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/'};
	
// Transfer all valid values to int
	int validIntValue[14];
	for (int i =0; i < 14; i++) {
		validIntValue[i] = (int)validValues[i];
	}
	
	int operatorIntValue[4];
	for (int i = 0; i < 4; i++) {
		operatorIntValue[i] = (int)operators[i];
	}
	
	int numberIntValue[10];
	for (int i = 0; i< 10; i++) {
		numberIntValue[i] = numbers[i];
	}
	
	cout << "Input the string (Any input int number should not start with 0):" << endl;
	cin >> inputValue;
	cout << endl;

// Check input value contains invalid characters
	bool validValue = true;
	for (int i = 0; i < inputValue.size(); i++) {
		int inputIntValue = (int)inputValue[i];
		validValue = isValueInArray(inputIntValue, validIntValue, sizeof(validIntValue)/sizeof(*validIntValue));
		if (validValue == false) {
			break;
		}
	}
	if (!validValue) {
		cout << "Input value '" << inputValue <<"' is not valid! Programe is going to terminated." << endl;
		return 0;
	}

//Check if the operator is valid or not
	bool validOperator = true;
	bool nextIsOperator = false;
	bool devideByZero = false;
	bool lastIsOperator = false;
	for (int i = 0; i < inputValue.size(); i++) {
		int inputIntValue = (int)inputValue[i];
		if (isValueInArray(inputIntValue, operatorIntValue, sizeof(operatorIntValue) / sizeof(*operatorIntValue))) {
			// Check if the operator is at the end of input string
			if (i == inputValue.size() - 1) {
				lastIsOperator = true;
				break;
			}
			// Check if 2 operators are next to each other
			nextIsOperator = isValueInArray((int)inputValue[i+1], operatorIntValue, sizeof(operatorIntValue) / sizeof(*operatorIntValue));
			if (nextIsOperator) {
				break;
			}
		}
	}
	if (nextIsOperator || lastIsOperator) {
		cout << "Input '" << inputValue << "' formula is not valid! Programe is going to terminated" << endl;
		return 0;
	}

// Input value is valid, do the calculation
	// Get number of operators in formula
	int operatorNum = 0;
	for (int i = 0; i < inputValue.size(); i++) {
		int inputIntValue = (int)inputValue[i];
		if (isValueInArray(inputIntValue, operatorIntValue, sizeof(operatorIntValue) / sizeof(*operatorIntValue))) {
			operatorNum++;
		}
	}
	// Create an array to store index of each operator (using dynamic array method)
	int totalElements = 2 * operatorNum + 1;
	int *pOperatorIndexArray = NULL;
	int *pTemp = NULL;
	int operatorCount = 0;
	int operatorIndex = 0;
	for (int i = 0; i < inputValue.size(); i++) {
		int inputIntValue = (int)inputValue[i];
		if (isValueInArray(inputIntValue, operatorIntValue, sizeof(operatorIntValue) / sizeof(*operatorIntValue))) {
			operatorIndex = i;
			
			pTemp = new int[operatorCount+1];
			if (pTemp != NULL){  
				*(pTemp + operatorCount) = operatorIndex;  
				for (int j = 0; j < operatorCount; j++)
					*(pTemp + j) = *(pOperatorIndexArray + j);
					delete[] pOperatorIndexArray;
					pOperatorIndexArray = pTemp;
				}
			operatorCount++;
		}
	}
	cout << operatorCount << endl;
	//Create array of all elements in formula
	int element
	string elemetsInFormula[2*operatorNum+1];
	int startIndex = 0;
	int endIndex =0;
	for (int i = 0; i < operatorCount; i++) {
		int currentIndex = *(pOperatorIndexArray+i);
		if (i == 0) {
			elemetsInFormula[i] = inputValue.substr(0,currentIndex-1);
			elemetsInFormula[i+1] = inputValue.substr(currentIndex, 1);
		}
	}

}