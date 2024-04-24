#include <iostream>
#include "complex.h"

using namespace std;

void mandel(complex c, int n, complex z[]);
complex mandel_single(complex c, int n);
complex op(complex comp, complex c);


int main() {
	{ complex c = { 0, 0 };
	const int n = 1;
	complex z[n];
	mandel(c, n, z);
	print(z, n); }
	//[ 0 ]
	{ complex c = { 0, 0 };
	const int n = 3;
	complex z[n];
	mandel(c, n, z);
	print(z, n); }
	//[ 0 0 0 ]
	{ complex c = { 1, 1 };
	const int n = 3;
	complex z[n];
	mandel(c, n, z);
	print(z, n); }
	//[ 0 1+1i 1+3i ]
	{ complex c = { -1, 0 };
	const int n = 6;
	complex z[n];
	mandel(c, n, z);
	print(z, n); }
	//[ 0 -1 0 -1 0 -1 ]
	{ complex c = { 0, 3 };
	const int n = 5;
	complex z[n];
	mandel(c, n, z);
	print(z, n); }
	//[ 0 +3i -9+3i 72-51i 2583-7341i ]
	return 0;
}


void mandel(complex c, int n, complex z[]) {
	for (int i = 0; i < n; i++) {
		z[i] = mandel_single(c, i);
	}
}


complex mandel_single(complex c, int n) {
	if (n == 0) {
		return complex {0, 0};
	} else {
		return op(mandel_single(c, n-1), c);
	}
}


complex op(complex comp, complex c) {
	complex v;
	int a = comp.real;
	int b = comp.img;
	v.real = a * a - b * b;
	v.img = a * b + b * a;
	v.real += c.real;
	v.img += c.img;
	return v;
}