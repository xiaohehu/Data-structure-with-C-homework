#include <iostream>

using namespace std;
int* getHeapMemory() {
	try {
		unsigned long int i = 1024;
		unsigned long int sum = 0;
		int *point;
		bool leak = false;
		while (!leak) {
			point = new int[i];
			if (point != NULL) {
				cout << "Address of this part's first byte is: ";
				cout << point << endl;
				sum += i;
				cout << "Currently total loacated heap size is:";
				cout << sum/256 << "k" << endl;
				cout << endl;
				i = i * 2;
			}
			else {
				leak = true;
				cout << "Memory leak.";
				return point;
			}
		}
	} catch (bad_alloc & ex) {
		cout << "Memory got leak.";
		return NULL;
	}
}


int main(int argc, char *argv[]) {
	getHeapMemory();
	return 0;
}