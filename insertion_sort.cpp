//Insertion Sort, CLRS implementation.

#include <iostream>


void insertionSort(int *arr, int length)
{
	for(int i{1}; i < length; i++)
	{
		int key = arr[i];
		int j{i - 1};
		while(j > 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int length{10};
	int arr[length] { 0, 5, 4, 3, 2 , 1,2913, 1213, 9};
	insertionSort(arr, length);
	for(auto i{0}; i < length; i++)
		std::cout << arr[i] << ' ';
	return 0;
}