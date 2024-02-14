//Array , Two Pointers , Simulation

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // vector<int> positive;
        // vector<int> negative;
        int positive = 0 , negative = 1;
        vector<int> res( nums.size() );

        for(int i=0 ; i<nums.size() ; i++){

            if( nums[i] > 0 ){
                // positive.push_back(nums[i]);
                res[positive] = nums[i];
                positive+=2;
            }
            else if( nums[i] < 0 ){
                // negative.push_back(nums[i]);
                res[negative] = nums[i];
                negative+=2;
            }
        }
        // for(int i=0 ; i<nums.size()/2 ; i+=2){
        //     res[i] = positive[i];
        //     res[i+1] = negative[i];
        // }
        return res;
        
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 1, -2, -5, 2, -4};
    vector<int> result1 = solution.rearrangeArray(nums1);
    cout << "Test Case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {-1, 1};
    vector<int> result2 = solution.rearrangeArray(nums2);
    cout << "Test Case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
