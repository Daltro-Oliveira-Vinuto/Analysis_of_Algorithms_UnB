typedef long long ll;

// In the worst case is O(n) by master method
// using the substituion n = log m for 
// T(n)=T(n-1)+a, T(0)=b
void print_recursive(ll* array, ll size) {
	if (size > 0) {
		print_recursive(array, size-1);
		printf("%lld ", array[size-1]); 
	}
}

void print_array(ll* array, ll size) {
	print_recursive(array, size);
	printf("\n");
}