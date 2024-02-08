#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size,1);

        // Compute the product of elements to the left of nums[i] and store it in res[i]
        for(int i=1 ; i<size ; i++){
            res[i] = res[i-1] * nums[i-1];
        }
        
        int right_product = 1; //Initialize the product to the right of nums[i] as 1

        // multiplying res with the product to the right of nums[i]
        for(int i=size-1 ; i>=0 ; i--){
            res[i] *= right_product;
            right_product *= nums[i];
        }
        // for(int i=0 ; i<nums.size() ; i++){
        //     int product = 1;

        //     for(int z=0 ; z<nums.size() ; z++){
        //         if(i == z) continue;
            
        //         product *= nums[z];
        //     }
        //     res.push_back(product);
        // }

        return res;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<vector<int>> test_cases = {
        {1, 2, 3, 4},
        {-1, 1, 0, -3, 3}
    };

    for (const auto& nums : test_cases) {
        vector<int> result = solution.productExceptSelf(nums);
        cout << "Input: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "\nOutput: ";
        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
