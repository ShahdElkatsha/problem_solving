//Array , Dynamic Programming

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int size = arr.size();
        vector<int> dp(size + 1, 0);
        // vector<int> maxSub(size, 0);

        for (int i = size-1; i >= 0; i--) { // the array in reverse
            int res = 0;  
            int temp = 0; //current element
            int len = 0;

            for (int z = i; z < min(i+k , size); z++) {
                len++;
                temp = max(temp, arr[z]);
                int currElement = temp * len + dp[z+1];
                res = max(res, currElement);
            }
            dp[i] = res; 
        }
        // for (int i = 0; i < size; ++i) {
        //     for (int z = 1; z <= k && (i - z + 1 >= 0); ++z) {
        //         dp[i+1] = max( dp[i+1] , dp[i-z]+maxSub[i]*z);
        //     }
        // }

        return dp[0];
        
    }
};

int main() {
    Solution solution;

    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    int result = solution.maxSumAfterPartitioning(arr, k);

    cout << "Output: " << result << endl;

    return 0;
}
