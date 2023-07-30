#include <bits/stdc++.h>
#include "factorial.cpp"

using namespace std;
typedef long long ll;

int main() {
	
	ll v, n;

	scanf("%lld", &v);

	n = factorial(v);

	printf("%lld\n", n);

	return 0;
}