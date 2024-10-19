#include <iostream>
#include <vector>
#include <algorithm>

int binarySearchLeftMost(const std::vector<int>& vec, int elem) {
	int left = 0;
	int right = vec.size() - 1;
	int result = -1;
	while (left <= right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid] == elem) {
			result = mid;
			right = mid - 1;
		}
		else if (vec[mid] < elem) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int binarySearchRightMost(const std::vector<int>& vec, int elem) {
	int left = 0;
	int right = vec.size() - 1;
	int result = -1;
	while (left <= right) {
		size_t mid = left + (right - left) / 2;
		if (vec[mid] == elem) {
			result = mid;
			left = mid + 1;
		}
		else if (vec[mid] < elem) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return result;
}

int main() {
	std::vector<int> vec{1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 10, 18};
	int rightIndex = binarySearchRightMost(vec, 3);
	int leftIndex = binarySearchLeftMost(vec, 3);
	leftIndex >= 0 ? std::cout << rightIndex - leftIndex + 1 : std::cout<<0;

	std::cout << std::upper_bound(vec.begin(), vec.end(), 3) - std::lower_bound(vec.begin(), vec.end(), 3);
}
