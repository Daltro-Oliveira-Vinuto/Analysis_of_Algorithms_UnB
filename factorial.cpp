typedef long long ll;

// factorial is O(n) using master method or substituion method
// after making the substition n = log m
ll factorial(ll n) {
	if (n == 0 ||  n == 1 ) return 1;
	else {
		return n * factorial(n-1);
	}
}