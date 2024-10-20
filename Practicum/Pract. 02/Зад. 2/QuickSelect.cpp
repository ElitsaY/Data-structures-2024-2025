#include <iostream>
#include <vector>
#include <algorithm>


int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int pivotIndex = left - 1;

    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            pivotIndex++;
            std::swap(nums[pivotIndex], nums[i]);
        }
    }
    std::swap(nums[pivotIndex + 1], nums[right]);
    return pivotIndex + 1;
}

int quickSelect(std::vector<int>& nums, int left, int right, int k) {
    int pivotIndex = partition(nums, left, right);
    if (pivotIndex == k) return nums[k];
    else if (pivotIndex > k) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    }
    else {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

int findKthLargest(std::vector<int>& nums, int k) {

    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
}