#include <iostream>

void merge(int *array, int start, int half, int end) {
	int i, j, k;
	int left_begin = start;
	int right_begin = half+1;
	int aux_array[end-start];

	i = left_begin;
	j = right_begin;
	k = 0;
	while (i <= half && j <= end) {
		if (array[i] <= array[j]) { aux_array[k] = array[i]; i++;}
		else { aux_array[k] = array[j]; j++;}
		k++;
	}

	while (i <= half) {
		aux_array[k] = array[i]; i++; k++;
	}

	while (j <= end) {
		aux_array[k] = array[j]; j++; k++;
	}

	for (k=0, i=start; i <= end; k++,i++) {
		array[i] = aux_array[k];
	}

}

/* merge sort is O(nlogn) in the worst case by the master method or
substituion method(using recursion-tree method too)
T(n) = 2*T(n/2) + cn = O(nlogn) 
*/

void merge_sort(int* array, int start, int end) {
	if (start == end) return;
	else {
		int half = start+(end-start)/2;
		merge_sort(array, start, half);
		merge_sort(array, half+1, end);

		merge(array, start, half, end);
	}
}

void sort_by_merge(int *array, int size) {

	merge_sort(array, 0, size-1);
}

/* Snippet of code to test merge_sort 
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

*/