#include <bits/stdc++.h>
#include "fractions.cpp"

using namespace std;

int main() {
	Fraction f2(800,200);
	Fraction f1(6,4);
	Fraction f3;

	cout << f1 << endl;
	cout << f2 << endl;

	cout << "f1+f2: " << f1+f2 << endl;
	cout << "f1-f2: " << f1-f2 << endl;
	cout << "f1*f2: " << f1*f2 << endl;
	cout << "f1/f2: " << f1/f2 << endl;
	cout << "f1 == f2: " << (f1 == f2) << endl;

	return 0;
}