typedef long long ll;

// binary_search has O(log n) by the master method or
// by the substitution method(using recursion-tree too)
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