#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                increasing = false;
            } else if (nums[i] < nums[i + 1]) {
                decreasing = false;
            }
            // If nums[i] is equal to nums[i + 1], no change in monotonic property
        }

        return increasing || decreasing;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {3, 2, 1};

    cout << "Is nums1 monotonic? " << boolalpha << solution.isMonotonic(nums1) << endl;
    cout << "Is nums2 monotonic? " << boolalpha << solution.isMonotonic(nums2) << endl;

    return 0;
}
