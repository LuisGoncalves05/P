#include <iostream>
#include <string>
#include <vector>

using namespace std;
string longest_prefix(const vector<string>& v);


int main() {
	cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
	//"ap"
	cout << "\"" << longest_prefix({ "ap", "apple", "apply", "ape", "april", "aq", "x" }) << "\"\n";
	//""
	cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";
	//"gee"
	cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
	//"sedates"
	cout << "\"" << longest_prefix({ "symmetricstalwartscorn'flowers", "symmetricShetland'ssuccessfully", "symmetricreceiver'shipsteed", "symmetricGrailsflown", "symmetricpromenadingoutflank", "symmetricdrugg'ingseizure", "symmetricsanctumsove'rprinting", "symmetricCitroentransgr'essed", "symmetricdissembledwinging", "symmetric'recoupingCinderella" }) << "\"\n";
	//"symmetric"
	return 0;
}


string longest_prefix(const vector<string>& v) {
	string prefix = v[0];
	for (string word: v) {
		int i = prefix.length();
		string s0 = word.substr(0, i);
		string s1 = prefix.substr(0, i);
		while (s0 != s1) {
			i--;
			s0 = word.substr(0, i);
			s1 = prefix.substr(0, i);
		}
		prefix = s1;
	}
	return prefix;
}
