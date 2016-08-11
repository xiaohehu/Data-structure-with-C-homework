/*
READ ME:

	1. create a varible to count times run the function names "runTimes"
	
	2. The initial value of the varible is 1 
	
	3. Each time when x > 1, the count should increase by 1
	
	4. In main(), after get the fibo number, print out the count
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class FIBO {
	public:
		FIBO ();
		int fibonacci (int);
		
		//(1) Create the times count
		int runTimes;
	private:
};

FIBO::FIBO() {
	
	//(2) The initial value of the coun is 1
	runTimes = 1;
}
int FIBO::fibonacci (int x) {
		
		if ( x > 1 ){
			
			//(3) Each time the func is called the count increases by 1
			runTimes++;
	 		return (fibonacci (x - 2) + fibonacci (x - 1));
		}
		return 1; 
}

int main ( )
{FIBO A;
 int inputNumber, count = 0;
 cout << "To produce a list of the first n Fibonacci numbers " << endl;
 cout << "Enter an integer number > 0 and <= 20, followed by <Enter>: ";
 cin >> inputNumber;
 if (!cin.eof() && cin.good() && inputNumber > 0 && inputNumber <= 20 ) {
 		cout << "Fibonacci number is "; 
			cout << A.fibonacci (inputNumber) << " ";
			
			//(4) Print out the count
			cout << endl;
			cout << "Times run the recursion: ";
			cout << size_t (A.runTimes) << endl;
		}
	else
		cout << "Invalid input value";
	cout << endl;
	cout << "Program terminating" << endl;
	return EXIT_SUCCESS;
}