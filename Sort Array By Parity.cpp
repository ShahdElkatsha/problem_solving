//Array, Two Pointers, Sorting

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {

        std::vector<int> res(nums.size());

        int z = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                res[z] = nums[i];
                z++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                res[z] = nums[i];
                z++;
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Example usage
    std::vector<int> nums = {3, 1, 2, 4, 7, 6, 5, 8};
    std::vector<int> sortedArray = solution.sortArrayByParity(nums);

    // Print the sorted array
    std::cout << "Sorted Array: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
