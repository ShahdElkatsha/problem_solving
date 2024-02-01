//Array , Math , Two Pointers

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size() ;
        k = k % size;    //if k > size

        // vector<int> rotated( nums.begin() +size -k , nums.end() );
        // rotated.insert(rotated.end() , rotated.begin() , nums.begin() + size - k);
        // nums = rotated;

        // 1 2 3 4 5 6 7 , 3
        reverse(nums.begin() , nums.begin()+(size-k));   //[4, 3, 2, 1, 5, 6, 7] , (0, 0+7-3)
        reverse(nums.begin()+(size-k) , nums.end());   //[4, 3, 2, 1, 7, 6, 5] , (0+7-3,7)
        reverse(nums.begin() , nums.end());   //[5, 6, 7, 1, 2, 3, 4]

      
    }

    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution solution;

    // Ex 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    solution.rotate(nums1, k1);

    cout << "Rotated Array (Example 1): ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    // Ex 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    solution.rotate(nums2, k2);

    cout << "Rotated Array (Example 2): ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
