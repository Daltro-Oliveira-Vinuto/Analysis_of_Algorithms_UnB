#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void merge(vector<int> &v, int start, int half, int end) {
	int i, j, k;
	int left_begin = start;
	int right_begin = half+1;
	int aux_v[end-start];

	i = left_begin;
	j = right_begin;
	k = 0;
	while (i <= half && j <= end) {
		if (v[i] <= v[j]) { aux_v[k] = v[i]; i++;}
		else { aux_v[k] = v[j]; j++;}
		k++;
	}

	while (i <= half) {
		aux_v[k] = v[i]; i++; k++;
	}

	while (j <= end) {
		aux_v[k] = v[j]; j++; k++;
	}

	for (k=0, i=start; i <= end; k++,i++) {
		v[i] = aux_v[k];
	}

}

/* merge sort has O(nlogn) in the worst case by the master method or
substituion method(using recursion-tree method too) */

void merge_sort(vector<int> &v, int start, int end) {
	if (start == end) return;
	else {
		int half = start+(end-start)/2;
		merge_sort(v, start, half);
		merge_sort(v, half+1, end);

		merge(v, start, half, end);
	}
}
