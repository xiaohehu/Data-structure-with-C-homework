#include <iostream>
using namespace std;
class mathCalculator
{
	public:
		void calculateAnswer (double, double, char);
};
void mathCalculator::calculateAnswer(double val1, double val2, char oprtr) {
	double answer = 0;
	int oprtrIndex = 0;
	bool devidZero = false;
	if (oprtr == '+') {
		oprtrIndex = 1;
	}
	if (oprtr == '-') {
		oprtrIndex = 2;
	}
	if (oprtr == '*') {
		oprtrIndex = 3;
	}
	if (oprtr == '/') {
		oprtrIndex = 4;
	}
	switch (oprtrIndex) {
		case 1:
			answer = val1 + val2;
			break;
		case 2:
			answer = val1 - val2;
			break;
		case 3:
			answer = val1 * val2;
			break;
		case 4:
			if (val2 == 0) {
				devidZero = true;
				break;
			}
			else {
				answer = val1/val2;
			}
			break;
		defalt:
			break;
	}
	if (devidZero) {
		cout << "Devided by Zero!" << endl;
	}
	cout << "The answer is: " << answer << endl;
}

class Container
{
	public:
		void getInputValue();
	private:
		double val1;
		double val2;
		char oprtr;
};

void Container::getInputValue() {
	while (!cin.eof() && cin.good()) {
		cout << "Please input first integer number: " << endl;
		cin >> val1;
		cout << "Please input operator: " << endl;
		cin >> oprtr;
		cout << "Please input second integer number: " << endl;
		cin >> val2;
		mathCalculator calculator;
		calculator.calculateAnswer(val1, val2, oprtr);
	}
}

using namespace std;
int main(int argc, char *argv[]) {
	Container container;
	container.getInputValue();
	return 0;
}