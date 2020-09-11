#include <iostream>

void merge(int *arr, int l, int m, int r){
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
	while(i < left_size and j < right_size){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
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
		j++;
		k++;
	}
}

void merge_sort(int *arr, int l, int r){
	if(l < r){
		int m = (l+r)/2;
		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);
		merge(arr, l, m , r);
	}
}

int main(){
	int arr[10] {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int size = 10;
	merge_sort(arr, 0, size - 1);
	for(int i{0}; i < size; i++){
		std::cout << arr[i] << "    ";
	}
	std::cout << std::endl;
	return 0;
}