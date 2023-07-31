#include <bits/stdc++.h>
#include "print_array_recursive.cpp"
#include "power.cpp"

using namespace std;
typedef long long ll;

int main() {
	ll b, p, n = 10;

	b = 3;
	for(ll e = 0; e <= n; e++) {
		p = pow(b, e);
		printf("%lld^%lld = %lld\n",b, e, p);
	}

	return 0;
}