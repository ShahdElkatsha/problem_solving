//Math, Dynamic Programming, Memoization
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        vector<int> ways(n + 1, 0);
        ways[1] = 1;
        ways[2] = 2;

        for (int i = 3; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n];
    }
};

int main() {
    Solution solution;

     int n1 = 2;
    cout << "Distinct ways to climb " << exampleN1 << " stairs: " << solution.climbStairs(n1) << endl;

    int n2 = 3;
    cout << "Distinct ways to climb " << exampleN2 << " stairs: " << solution.climbStairs(n2) << endl;

    return 0;
}
