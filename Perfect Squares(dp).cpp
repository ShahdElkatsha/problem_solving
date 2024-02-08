//Math , Dynamic Programming , Breadth-First Search

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<long long> dp(n + 1, INT_MAX); 
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int z = 1; z * z <= i; ++z) {
                dp[i] = min(dp[i], dp[i - z * z] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;

    // Test cases
    cout << "numSquares(12): " << solution.numSquares(12) << endl;
    cout << "numSquares(13): " << solution.numSquares(13) << endl;

    return 0;
}
