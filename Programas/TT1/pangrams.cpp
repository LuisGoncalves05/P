#include <iostream>

using namespace std;

bool pangram(const char s[], char m[]);

int tolower(char idx) {
	if (idx >= 'A' && idx <= 'Z') {
		return (int) idx - 'A' + 'a';
	}
	return (int) idx;
}


int main() {
	{ char s[] = "";
	char m[27] = { -1 };
	bool r = pangram(s, m);
	cout << '\"' << s << "\" "
		<< boolalpha << r << " \"" << m << "\"\n"; }
	//"" false "abcdefghijklmnopqrstuvwxyz"
	{ char s[] = "The quick brown fox jumps over the lazy dog";
	char m[27] = { -1 };
	bool r = pangram(s, m);
	cout << '\"' << s << "\" " 
		<< boolalpha << r << " \"" << m << "\"\n"; }
	//"The quick brown fox jumps over the lazy dog" true ""
	{ char s[] = "A quick brown fox jumps over a classy dog";
	char m[27] = { -1 };
	bool r = pangram(s, m);
	cout << '\"' << s << "\" " 
		<< boolalpha << r << " \"" << m << "\"\n"; }
	//"A quick brown fox jumps over a classy dog" false "htz"
	{ char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
	char m[27] = { -1 };
	bool r = pangram(s, m);
	cout << '\"' << s << "\" " 
		<< boolalpha << r << " \"" << m << "\"\n"; }
	//" abC dEf GhI jKl MnO pQr StU vWx yZ " true ""
	{ char s[] = " Stu yZ abC GhI MnO pQr   ";
	char m[27] = { -1 };
	bool r = pangram(s, m);
	cout << '\"' << s << "\" " 
		<< boolalpha << r << " \"" << m << "\"\n"; }
	//" Stu yZ abC GhI MnO pQr   " false "defjklvwx"
	return 0;
}


bool pangram(const char s[], char m[]) {
	bool arr[26] = {false};
	int i = 0;
	while (s[i] != '\0') {
		int idx = tolower(s[i]);
		if (idx >= 'a' && idx <= 'z') {
			idx -= 'a';
			arr[idx] = true;
		}
		i++;
	}
	int idx = 0;
	bool ret = true;
	for (int j = 0; j < 26; j++) {
		if (!(arr[j])) {
			m[idx] = j + 'a';
			idx++;
		}
		ret &= arr[j]; 
	}
	m[idx] = '\0';
	return ret;
}