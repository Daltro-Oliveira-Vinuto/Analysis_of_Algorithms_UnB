
// Insertion_sort is O(n^2) because in the worst case it
// make a sum of a AR(arithmetic progression) operations
void insertion_sort(int *array, int n) {
	int i, j;
	int key;

	for(i = 1; i<n; i++) {
		key = array[i];
		j = i-1;
		while (j >= 0 && array[j] > key) {
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = key;
	}
}

/* snippet to test -------------------------
// file used for test algorithms

#include <iostream>
#include "insertion_sort.cpp"

using namespace std;

void print_array(int* , int);

int main() {
	int test_array[5] = {5, 1, 3, 2, 4};

	cout << "Before sort: ";
	print_array(test_array, 5);

	insertion_sort(test_array, 5);

	cout << "After sort: ";
	print_array(test_array, 5);

	return 0;
}


void print_array(int* array, int n) {
	for(int i = 0; i < n ;i++) {
		cout << array[i] << " , ";
	}
	cout << endl;
}

*/