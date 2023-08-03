#include <math.h>
#include "matrix.cpp"

typedef long long ll;

// The complexity is exponential using master method
// T(n) = T(n-1) + T(n-2) + 1 <= 2*T(n-1) + 1 <= O(2^n)
// T(n) = T(n-1) + T(n-2) + 1 >= 2*T(n-2) +1 >= O(sqrt(2)^n)
ll fibonacci_slow(ll n) {
	if (n == 0 || n == 1) return 1;
	else {
		return fibonacci_slow(n-1) + fibonacci_slow(n-2);
	}
}

// The complexity is O(n) because there's only one loop
ll fibonacci_linear(ll n) {
	ll a, b, c;

	a = 1;
	b = 0;
	c = 0;

	for(ll i = 1; i<= n; i++) {
		c = a+b;
		a = b;
		b = c;
	}

	return c;
}

// The complexity is O(1) but it is unreliable
// because of the arithmetic of float point numbers
ll fibonacci_constant(ll n) {
	double fi = (1.0 + sqrt(5.0))/2.0;
	return (ll)pow(fi, n)/sqrt(5.0);
}

// The complexity is O(log n) because
// T(n) = T(n/2) + O(1) = O(log n)
ll fibonacci(ll n) {
	Matrix matrix(2, 2), pow_matrix(2,2);
	ll result;

	matrix.update(1, 0, 0); matrix.update(1, 0, 1);
	matrix.update(1, 1, 0); matrix.update(0, 1, 1);

	pow_matrix = matrix.power(n); // fast exponention in O(log n)

	result = pow_matrix.get_value(0, 1);

	return result;
}