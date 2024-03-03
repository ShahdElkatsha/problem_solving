//Array , Math , Dynamic Programming , Sorting

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());

        int size = nums.size();
        vector<int> dp(size , 1); //store the length of the largest divisible subset 
        vector<int> parent(size , -1); //store index of previous element in largest divisible subset 

        int maxIdx = 0; //store index of maximum length divisible subset found
        
        for(int i=1 ; i<size ; i++){
            for(int z=0 ; z<i ; z++){
                
                if(nums[i] % nums[z] == 0 && dp[i] < dp[z] + 1){
                    dp[i] = dp[z] + 1;
                    parent[i] = z;
                }
            }
            if( dp[i] > dp[maxIdx]){
                maxIdx = i ;
            }
        }
        vector<int> res;
        while(maxIdx != -1){
            res.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        reverse(res.begin(),res.end());     //maintain original order
        return res;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> nums1 = {1, 2, 3};
    vector<int> result1 = solution.largestDivisibleSubset(nums1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {1, 2, 4, 8};
    vector<int> result2 = solution.largestDivisibleSubset(nums2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
