//CLRS Merge Sort implementation: currently incomplete

#include <iostream>
#include <vector>

void merge(std::vector<int> &arr, int p, int q, int r)
{
	int n1 = (q - p) + 1;
	int n2 = (r - q);
	int i{0}, j{0};
	std::vector<int> left(n1);
	std::vector<int> right(n2);

	for(i = 0; i < n1; i++)
		left[i] = arr[i + p];
	for(j = 0; j < n2; j++)
		right[j] = arr[j + q];
	i = 0;
	j = 0;
	int k = p;
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

    while(i < n1)
    	arr[k++] = left[i++];
  
    while(j < n2)
    	arr[k++] = right[j++];
}

void mergeSort(std::vector<int> &arr, int p, int r)
{
	if(p < r)
	{
		int q = p + (r - 1) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}
int main()
{
	int n{0};
	std::cout << "Enter the size of the array: ";
	std::cin >> n;
	std::cout << "Enter the array: ";
	std::vector<int> arr(n);
	for(int i{0}; i < n; i++)
		std::cin >> arr[i];

	std::cout << "Array before Sorting\n";
	for(auto &element: arr)
		std::cout << element << ' ';

	mergeSort(arr, 0, int(arr.size() - 1));

	std::cout << "\nArray After Sorting:\n";
	for(auto &element: arr)
		std::cout << element << ' ';
	std::cout << std::endl;
	return 0;
}