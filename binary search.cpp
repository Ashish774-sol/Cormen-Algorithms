#include <iostream>

int binarySearch(int *arr, int lower, int upper, int value){
	if(lower <= upper){
		int middle = (lower + upper)/2;
		if(arr[middle] == value)
			return middle;
		else if(arr[middle] > value)
			return binarySearch(arr, lower, middle - 1, value);
		else
			return binarySearch(arr, middle + 1, upper, value);
	}
	return -1;
}


int main(){
	int arr[] = {1, 2, 3, 4, 12, 16, 17, 23, 41};
	int value = 12;
	std::cout << value << " was found at index " << binarySearch(arr, 0, 8, value);
	return 0;
}