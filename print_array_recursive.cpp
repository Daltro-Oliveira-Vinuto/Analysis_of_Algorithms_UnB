typedef long long ll;

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