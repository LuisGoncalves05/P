#include <iostream>
using namespace std;

char* repeat(const char str[], int n);
int len(const char* str);


int main() {
	{ const char str[] = "H e l l o";
	char* r = repeat(str, 2);
	cout << "\"" << r << "\"\n";
	delete [] r; }
	//"H e l l oH e l l o"
	{ const char str[] = "C++";
	char* r = repeat(str, 1);
	cout << "\"" << r << "\"\n";
	delete [] r; }
	//"C++"
	{ const char str[] = "";
	char* r = repeat(str, 99);
	cout << "\"" << r << "\"\n";
	delete [] r; }
	//""
	{ const char str[] = "C/C++@LEIC.";
	char* r = repeat(str, 5);
	cout << "\"" << r << "\"\n";
	delete [] r; }
	//"C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC."
	{ const char str[] = "x";
	char* r = repeat(str, 15);
	cout << "\"" << r << "\"\n";
	delete [] r; }
	//"xxxxxxxxxxxxxxx"
	return 0;
}


char* repeat(const char str[], int n) {
	char* ret = new char[len(str)*n + 1];
	int j = 0;
	for (int i = 0; i < n; i++) {
		j = 0;
		while (str[j]) {
			ret[j + i*len(str)] = str[j];
			j++;
		}
	}
	ret[n*len(str)] = str[j];
	return ret;
}


int len(const char* str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}
