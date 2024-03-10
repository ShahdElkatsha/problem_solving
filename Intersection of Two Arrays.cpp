//Array , Hash Table , Two Pointers , Binary Search , Sorting
/*
the problem:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        set<int> res;

        for (auto num : set1) {
            if (set2.find(num) != set2.end()) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
