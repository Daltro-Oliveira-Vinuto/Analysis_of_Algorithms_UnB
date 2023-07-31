typedef long long ll;

// The complexity is O(n) because of the loop
ll pow_slow(ll n, ll e) {
	ll p = 1;

	for(ll i = 1; i <= e; i++) {
		p*= n;
	}

	return p;
}

// the complexity is O(n) by the master method
// because T(n) = 2*T(n/2) + O(1) = O(n)
ll pow_slow_recursive(ll n, ll e) {
	if (e == 0) return 1;
	else if (e == 1) return n;
	else if (e%2 == 0) {
		return pow_slow_recursive(n, e/2)*pow_slow_recursive(n, e/2);
	} else {
		return n*pow_slow_recursive(n, e/2)*pow_slow_recursive(n, e/2);
	}
}

// the complexity is O(logn) by the master method
// because T(n) = T(n/2) + O(1) = O(log n)
ll pow(ll n, ll e) {
	if (e == 0) return 1;
	else if (e == 1) return n;
	else if (e%2 == 0) {
		ll power;
		power = pow(n, e/2);
		return power*power;
	} else {
		ll power;
		power = pow(n, e/2);
		return n*power*power;
	}
}