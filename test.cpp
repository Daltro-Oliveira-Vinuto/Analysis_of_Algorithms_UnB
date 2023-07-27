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