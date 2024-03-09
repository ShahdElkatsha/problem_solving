//Array , Hash Table , Two Pointers , Binary Search

/*
the problem:
Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common = -1;
        int i = 0, z = 0;
        while (i < nums1.size() && z < nums2.size()) {
            if (nums1[i] == nums2[z]) {
                common = nums1[i];
                break;
            } 
            else if (nums1[i] < nums2[z]) {
                i++;
            }
            else {
                z++;
            }
        }
        return common ;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4};
    int common = solution.getCommon(nums1, nums2);
    cout << "Common integer: " << common << endl;
    return 0;
}
