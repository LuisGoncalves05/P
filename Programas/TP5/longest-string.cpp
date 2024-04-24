#include <iostream>

using namespace std;

const char* longest(const char* pa[]);
int batatalen(const char* steringue);

int main() {
	{ const char* pa[] = { "C++", nullptr };
	cout << "\"" << longest(pa) << "\"\n"; }
	//"C++"
	{ const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
	cout << "\"" << longest(pa) << "\"\n"; }
	//"world"
	{ const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
	cout << "\"" << longest(pa) << "\"\n"; }
	//"Hello world"
	{ const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
	cout << "\"" << longest(pa) << "\"\n"; }
	//"Hello world!"
	{ const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
	cout << "\"" << longest(pa) << "\"\n"; }
	//"Typescript"	
	return 0;
}

const char* longest(const char* pa[]) {
	int i = 1;
	int max_idx = 0;
	while (const char* steringue = pa[i]) {
		int curr_len = batatalen(steringue);
		if (curr_len >= batatalen(pa[max_idx])) {
			max_idx = i;
		}
		i++;
	}
	return pa[max_idx];
}

int batatalen(const char* steringue) {
	int i = 0;
	while (steringue[i]) i++;
	return i;
}