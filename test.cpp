#include <bits/stdc++.h>
#include "binary_search_first.cpp"

using namespace std;


int main() {
	ll n, q;

	scanf("%lld %lld", &n, &q);

	ll array[n];

	for(ll i = 0; i <n; i++) {
		scanf("%lld", &array[i]);
	}

	for(ll i = 0; i <q; i++) {
		ll value, state;

		scanf("%lld", &value);

		state = binary_search_first(array, value, 0, n-1);
		
		printf("%lld\n", state);
	}


	return 0;
}