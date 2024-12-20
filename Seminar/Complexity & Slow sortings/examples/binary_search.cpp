#include <iostream>

template <class T>
int binarySearch(const T* arr, int len, const T& searched)
{
	int leftIndex = 0;
	int rightIndex = len - 1;
	while (leftIndex <= rightIndex)
	{
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

		if (arr[midIndex] == searched)
			return midIndex;
		
		if (arr[midIndex] > searched)
			rightIndex = midIndex - 1;
		else
			leftIndex = midIndex + 1;
	}
	return -1;

}
