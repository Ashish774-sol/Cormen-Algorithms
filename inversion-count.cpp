#include <iostream>

int merge_inversions(int *arr, int l, int m, int r){
	int left_size = m - l + 1;
	int right_size = r - m;
	int *left = new int[left_size];
	int *right = new int[right_size];
	for(int i{0}; i < left_size; i++){
		left[i] = arr[i + l];
	}
	for(int i{0}; i < right_size; i++){
		right[i] = arr[m + i + 1];
	}
	int i = 0;
	int j = 0;
	int k = l;
	int inversions = 0;
	while(i < left_size and j < right_size){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			inversions += left_size - i + 1;
			j++;
		}
		k++;
	}
	while(i < left_size){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < right_size){
		arr[k] = right[j];
		inversions += left_size - i + 1;
		j++;
		k++;
	}
	return inversions;
}

int inversion_counts(int *arr, int l, int r){
	int inversions = 0;
	if(l < r){
		int m = (l+r)/2;
		int left = inversion_counts(arr, l, m);
		int right = inversion_counts(arr, m+1, r);
		inversions = merge_inversions(arr, l, m , r) + left + right;
	}
	return inversions;
}

int main(){
	return 0;
}