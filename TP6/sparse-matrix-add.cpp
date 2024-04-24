#include "smatrix.h"
#include <iostream>

using namespace std;

bool operator ==(const sm_entry a, const sm_entry b); 
bool operator >(const sm_entry a, const sm_entry b);
bool operator <(const sm_entry a, const sm_entry b);
void sum(const smatrix& a, const smatrix& b, smatrix& r);


int main(){
	{ smatrix r;
	sum({ },
		{ {0, 3, 1}, {0, 50, 1} },
		r);
	print(r); }
	//[ (0, 3, 1) (0, 50, 1) ]
	{ smatrix r;
	sum({ {0, 0, 1}, {1, 0, 1} },
		{ {0, 3, 1}, {0, 50, 1} },
		r);
	print(r); }
	//[ (0, 0, 1) (0, 3, 1) (0, 50, 1) (1, 0, 1) ]
	{ smatrix r;
	sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
		{ {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
		r);
	print(r); }
	//[ (0, 0, 2) (5, 10, 20) (10, 5, 20) (99, 10, 30) (99, 11, 31) (99, 12, 32) ]
	{ smatrix r;
	sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
		{ {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
		r);
	print(r); }
	//[ (5, 10, 20) ]
	{ smatrix r;
	sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
		{ {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
		r);
	print(r); }
	//[ ]
	return 0;
}


bool operator ==(const sm_entry a, const sm_entry b) {
	return (a.row == b.row && a.col == b.col);
}

bool operator >(const sm_entry a, const sm_entry b) {
	return ((a.row == b.row && a.col > b.col) || a.row > b.row);
}

bool operator <(const sm_entry a, const sm_entry b) {
	return (!(a == b || a > b));
}

void sum(const smatrix& a, const smatrix& b, smatrix& r){
	size_t idxa = 0;
	size_t idxb = 0;
	while (idxa < a.size() || idxb < b.size()) {
		if (idxa == a.size()){
			r.push_back(b[idxb]);
			idxb++;
		} else if (idxb == b.size()){
			r.push_back(a[idxa]);
			idxa++;
		} else {
			const sm_entry acurrent = a[idxa];
			const sm_entry bcurrent = b[idxb];
			if (acurrent == bcurrent) {
				int sum = acurrent.value + bcurrent.value;
				sm_entry res = {acurrent.row, acurrent.col, sum};
				if (sum) r.push_back(res);
				idxa++;
				idxb++;
			} else if (acurrent > bcurrent) {
				r.push_back(bcurrent);
				idxb++;
			} else {
				r.push_back(acurrent);
				idxa++;
			}
		}
	}
}