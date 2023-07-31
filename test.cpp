#include <bits/stdc++.h>
#include "print_array_recursive.cpp"
#include "fibonacci.cpp"

using namespace std;
typedef long long ll;

int main() {
	ll n, f;

	n = 50;
	for(ll i = 1; i <= n; i++) {
		f = fibonacci_linear(i);
		printf("%lld\n", f);
	}

	return 0;
}