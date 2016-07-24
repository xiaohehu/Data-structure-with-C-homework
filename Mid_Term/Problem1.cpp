#include <iostream>

using namespace std;

bool isValueInArray(int val, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (val == arr[i])
            return true;
    }
    return false;
}

int getOperatorIndex(int val, int *arr, int size) {
	for (int i = 0; i< size; i++) {
		if (val == arr[i]) {
			return i;
		}
	}
	return -1;
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
		cout << (int)operators[i] << endl;
	}
	
	int numberIntValue[10];
	for (int i = 0; i< 10; i++) {
		numberIntValue[i] = numbers[i];
	}
	
	cout << "Input the string (Any input int number should not start with 0):" << endl;
	cin >> inputValue;
	cout << endl;

// Check input value is valid or not
	bool validValue = true;
	for (int i = 0; i < inputValue.size(); i++) {
		int inputIntValue = (int)inputValue[i];
		validValue = isValueInArray(inputIntValue, validIntValue, sizeof(validIntValue));
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
	int operatorIndex = -1;
	bool nextIsOperator = false;
	bool devideByZero = false;
	for (int i = 0; i < inputValue.size(); i++) {
		cout << i << endl;
		int inputIntValue = (int)inputValue[i];
		if (isValueInArray(49, operatorIntValue, sizeof(operatorIntValue))) {
			cout << inputValue[i] << " " << inputIntValue << endl;
			nextIsOperator = isValueInArray((int)inputValue[i+1], operatorIntValue, sizeof(operatorIntValue));
			if (nextIsOperator) {
				break;
			}
		}
	}
	if (nextIsOperator) {
		cout << "Input '" << inputValue << "' formula is not valid! Programe is going to terminated" << endl;
		return 0;
	}
	else {
		cout << "hahahahha";
	}

}