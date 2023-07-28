// file used for test algorithms

#include <iostream>
#include "merge_sort.cpp"

using namespace std;

void print_array(int* , int);

int main() {
	int test_array[5] = {5, 1, 3, 2, 4};

	int size = sizeof(test_array)/sizeof(test_array[0]);

	cout << "Before sort: ";
	print_array(test_array, size);

	sort_by_merge(test_array, size);

	cout << "After sort: ";
	print_array(test_array, size);

	return 0;
}


void print_array(int* array, int n) {
	for(int i = 0; i < n ;i++) {
		cout << array[i] << " , ";
	}
	cout << endl;
}