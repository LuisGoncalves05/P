#include <iostream>

using namespace std;

unsigned long hstr_to_integer(const char hstr[]);

int main() {
	cout << hstr_to_integer("0") << endl;
	//0
	cout << hstr_to_integer("A") << endl;
	//10
	cout << hstr_to_integer("19") << endl;
	//25
	cout << hstr_to_integer("fF") << endl;
	//255
	cout << hstr_to_integer("CafeBabe2022") << endl;
	//223195403526178
	return 0;
}


unsigned long hstr_to_integer(const char hstr[]) {
	int i = 0;
	unsigned long j = 1;
	unsigned long res = 0;
	while (hstr[i] != '\0') {
		i++;
	}
	i--;
	char letter;
	while (i >= 0) {
		letter = hstr[i];
		if (letter >= 65 && letter <= 71) {
			letter -= 55;
		} else if (letter >= 97 && letter <= 102) {
			letter -= 87;
		} else if (letter >= 48 && letter <= 57) {
			letter -= 48;
		}
		res += j*letter;
		j*=16;
		i--;
	}
	return res;
}