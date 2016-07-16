// John Maslanka -- CS341 in class demo Feb 10, 2016
// C++ program for the Quadratic Formula using a C++ class, object and methods.
// This program contains the cleaned up code from last night's version of this 
// program. Also, I have included a lot of comments.  Some indicate why I did 
// some things in certain ways.  Other comments give instructions on how to break
// out this code into three files for use with MSVS Project or similar compilation
// and link managers.

// Please note that every file in your program should have header information, which
// includes your name, date, purpose and a brief description as shown above.

// For use with MSVS Project the #includes should go in the main along with #pragma
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// For use with MSVS Project put this class definition in its own Quadratic.h file
//  and remove its code from here.
class Quadratic {
	public:
		Quadratic (); // default constructor
		Quadratic ( int, int, int ); // overload constructor -- parameters at this
			// level only have to specify the parameter types.
		int Discrim (); 
		double bOver2A (); 
		double radicalOver2A ();
	private:
		double a, b, c, disc;
};

// For use with MSVS Project put these full method definitions in a file named 
//  Quadratic.cpp, which should contain the syntax #include Quadratic.h at its 
//  top so that the compiler can use its symbols when it compiles this file. 
//  Also, remove this method code from here.
	Quadratic::Quadratic () // default constructor
			{ a = b = c = 0; }
	Quadratic::Quadratic ( int A, int B, int C ) // overload constructor
			{ a = A; b = B; c = C; }
int Quadratic::Discrim () {
	disc = (b*b - 4*a*c);
	return (int) disc;
	}
double Quadratic::bOver2A () {

	return - b / (2 * a);  // fix sign-reversal bug
	}
double Quadratic::radicalOver2A () {
	return - sqrt(disc)/(2*a);  // fix sign-reversal bug
	}

// For use with MSVS Project put the main in a separate .cpp file with a name such 
//  as TestQuadratic.cpp. Once the Quadratic.h and Quadratic.cpp codes have been 
//  removed from this file, the heading at the top of this file will be just above
//  this comment. Be sure to insert right here the line of code which says 
//  #include Quadratic.h  // to give this program access to the symbols for the 
//  Quadratic code.
int main () {
	double a,b,c;
	int Disc = 0;
	// Please note: I try to put as much of the keyboard and terminal IO as possible
	//  in the main or in non-class functions to keep clutter our of the class and
	//  method definitions.
	// Please give the user appropriate prompts to instruct him how to use the program.
	cout << "Welcome to the Quadratic Formula program." << endl ;
	cout << "Enter Coefficients a, b and c from your quadratic equation" << endl;
	cout << "Note: coefficient a must be 0" << endl;

	// Please note: I did the inputs of all three variables on one cin statement. 
	// This is a quickie and is not quite as effective as using a separate cin 
	// statement for each variable and testing each variable separately.  If the 
	// use enters the keyboard EOF command the test immediately following the cin
	// statement will handle the input of the EOF command as a single character 
	// rather than as a specialized system command.
	cin >> a >> b >> c;
	if (!cin.eof() && cin.good() && a != 0) {
		Quadratic Q (a, b, c); // Try to declare objects after data input is complete
				// because setting up an object at runtime is an expensive operation.
				
				
/* Put this part code into a container				
				
				
		Disc = Q.Discrim();
		if (Disc < 0) {
			cout << "No real roots" << endl;
			}
		else if (Disc == 0) {
			cout << " One root: " << Q.bOver2A () << endl;
			}
		else { // If Disc > 0
			cout << " Two Roots: " << Q.bOver2A () + Q.radicalOver2A ()
			<< " and " << Q.bOver2A () - Q.radicalOver2A () << endl;
			}
		}
		
*/		
		
	else
		{if (!cin.eof()) {
			if (!cin.good())
				cout << "Invalid input data." << endl;
			else
				cout << "Coefficient a must not be 0." << endl;
			}
		cout << "Thank you for using the Quadratic program." << endl;
		}
	return 0;
}

