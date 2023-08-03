#include <bits/stdc++.h>
//#include "matrix.cpp"
#include "fibonacci.cpp"

typedef long long ll;


int main() {
	/**
	ll rows, cols;

	Matrix matrixA(3, 3), matrixB(3, 3), matrixC(3, 3), matrixD(3,3);

	matrixA.get_dimensions(&rows, &cols);

	for(ll i= 0; i < rows; i++) {
		for (ll j = 0; j < cols; j++) {
			matrixA.update(1, i, j);
		}
	}

	for(ll i= 0; i < rows; i++) {
		for (ll j = 0; j < cols; j++) {
			matrixB.update(2, i, j);
		}
	}

	//matrixA.get_identity().print();

	matrixA.print();
	matrixB.print();
	matrixC = matrixA + matrixB;

	matrixC.print();

	matrixD = matrixA * matrixB;

	matrixD.print();

	**/

	for(ll i = 0; i <= 50; i++) {
		printf("%lld\n", fibonacci(i));
	}
	/*
	for(ll i = 0; i <= 50; i++) {
		printf("%lld\n", fibonacci_linear(i));
	}
	*/

	return 0;
}