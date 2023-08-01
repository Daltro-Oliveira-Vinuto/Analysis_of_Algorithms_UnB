
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

	for(ll i = 2; i<= n; i++) {
		c = a+b;
		a = b;
		b = c;
	}

	return c;
}