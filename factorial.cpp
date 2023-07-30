typedef long long ll;

// factorial is O(n) using master method or substituion method
// after making the substition n = log m 
// T(n) = T(n-1)+a, T(0)= b
ll factorial(ll n) {
	if (n == 0 ||  n == 1 ) return 1;
	else {
		return n * factorial(n-1);
	}
}