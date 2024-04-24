#include <iostream>
#include "print_string.h"
#include <vector>
#include <string>


void split(const string& s, vector<string>& v);

int main() {
	{ string s = "";
	vector<string> v;
	split(s, v);
	print(v); }
	//[ ]
	{ string s = "    ";
	vector<string> v;
	split(s, v);
	print(v); }
	//[ ]
	{ string s = "  a b  c ";
	vector<string> v;
	split(s, v);
	print(v); }
	//[ "a" "b" "c" ]
	{ string s = "C++ LEIC FCUP FEUP";
	vector<string> v;
	split(s, v);
	print(v); }
	//[ "C++" "LEIC" "FCUP" "FEUP" ]
	{ string s = "       C++        ";
	vector<string> v;
	split(s, v);
	print(v); }
	//[ "C++" ]
	return 0;
}


void split(const string& s, vector<string>& v) {
	if (s.length() > 0) {
		vector<int> idxs;
		int idx = -1;

		if (s[0] != ' ') {
			idxs.push_back(-1);
		}

		while (idx + 1 < (int) s.length()) {
			idx = s.find(' ', idx + 1);
			if (idx != -1) {
				idxs.push_back(idx);
			} else break;
		}

		idx = s.length()-1;
		if (s[idx] != ' ') {
			idxs.push_back(idx+1);
		}
		
		for (size_t i = 0; i + 1 < idxs.size(); i++) {
			int l = idxs[i+1] - idxs[i] - 1;
			if (l > 0) {
				string word = s.substr(idxs[i] + 1, l);
				v.push_back(word);
			}
		}
	} 
}