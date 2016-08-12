#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

// Create a templet function for swap
template <class T>
void swap ( T* x, T* y )
{
	if(*x > *y){
  		T temp = *x;
  		*x = *y;
  		*y = temp;
	}
}


int main () {
	/*
		Input value is int 
	*/
    int i, j, x[200000];
    int n, t1, t2;
    cout << "Enter the number of integers to be entered: ";
    cin >> n;
    if (!cin.eof() && cin.good())
    {
    for (i = 0; !cin.eof() && cin.good() && i < n; ++i)  
    cin >> x[i];  
    if (!cin.eof() && cin.good()) {  
        cout << "Initial array is " << endl;
    for (i = 0; i < n; ++i)
      cout << x[i] << endl;
    // beginning of sorting code
    for (i = 0; i < n-1; ++i)
      for (j = 0; j < n-1-i; ++j)
         swap (x+j, x+j+1);
    // end of sorting code
      cout << "Sorted array is " << endl;
    for (i = 0; i < n; ++i)
        cout << " " << x[i];
        cout << endl;
      }
    else
    cout << "Invalid input" << endl;
    }
    cout << "Program terminating" << endl;
    system("PAUSE");


	/*
		Input value is double 
	*/

    int m, l, o; 
    double k[200000];
    double p, q;
    cout << "Enter the number of decimal to be entered: ";
    cin >> o;
    if (!cin.eof() && cin.good())
    {
    for (m = 0; !cin.eof() && cin.good() && m < o; ++m)  
     cin >> k[m];  
    if (!cin.eof() && cin.good()) {  
    cout << "Initial array is " << endl;
    for (m = 0; m < o; ++m)
      cout << k[m] << endl;
    // beginning of sorting code
    for (m = 0; m < o - 1; ++m)
      for (l = 0; l < o - 1 - m; ++l)
         swap (k+l, k+l+1);
    // end of sorting code
    cout << "Sorted array is " << endl;
    for (m = 0; m < o; ++m)
       cout << k[m] << endl;
      }
    else
    cout << "Invalid input" << endl;
    }
   cout << "Program terminating" << endl;
   system("PAUSE");
      return EXIT_SUCCESS;
}