#include <iostream>

using namespace std;


int main() {
	char r;
	cin >> r;
	if ((r >= 'a' && r <= 'z') || 
	    (r >= 'A' && r <= 'Z')) {
		cout << "LETTER" << endl;
	} else if (r >= '0' && r <= '9') {
		cout << "DIGIT" << endl;
	} else {
		cout << "OTHER" << endl;
	}
	return 0;
}