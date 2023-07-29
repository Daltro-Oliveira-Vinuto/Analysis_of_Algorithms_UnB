#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binary_search_first(ll *array, ll key, ll low, ll high) {
	if (low > high) return -1;
	else {
		ll half = low + (high-low)/2;

		// we use && (half==0 || array[half-1] != key) to
		// find the first ocorrence of the value
		if (array[half] == key && (half==0 || array[half-1] != key)) 
			return half;
		else if (key > array[half]) 
			 return binary_search_first(array, key, half+1, high);
		else // key <= array[half]
			// if not the first ocorrence then keep looking in the lower indexes
			return binary_search_first(array, key, low, half-1); 
	}

}

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