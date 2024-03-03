//Dynamic Programming , Depth-First Search , Breadth-First Search , Graph , Heap (Priority Queue) , Shortest Path

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // 'numeric_limits<int>::max()' to represent infinity.
        vector<int> dp(n, numeric_limits<int>::max());  //to store minimum costs to reach each city.
        dp[src] = 0;    // (src) to 0 as starting point.
        
        for (int i = 0; i <= k; ++i) {
            
            vector<int> temp = dp;  // a temporary vector 'temp' to store updated costs during current iteration.

            for (const auto& flight : flights) {
                // Check if cost to reach starting city of the current flight is not infinite
                if (dp[flight[0]] != numeric_limits<int> ::max()) {
                   
                    // Update the cost in the temporary vector 'temp' for the destination city
                    temp[flight[1]] = min(temp[flight[1]], dp[flight[0]] + flight[2]);
                }
            }
            // Update main 'dp' vector
            dp = temp;
        }
        //    - If cost of destination city (`dp[dst]`) is still infinite, return -1 (unreachable).
        //    - Otherwise, return the minimum cost stored in `dp[dst]`.
        return dp[dst] == numeric_limits<int>::max() ? -1 : dp[dst];
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, k = 1;
    
    int cheapestPrice = solution.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price from " << src << " to " << dst << " with at most " << k << " stops: " << cheapestPrice << endl;

    return 0;
}
