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
        dp[src] = 0;    // (src) to 0 as it's the starting point.
        
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
   // Get input values from the user
   int n, src, dst, k;
   vector<vector<int>> flights;

   cout << "Enter the number of cities (n): ";
   cin >> n;

   cout << "Enter the number of flights: ";
   int numFlights;
   cin >> numFlights;

   cout << "Enter the flight details (source, destination, price) for each flight:\n";
   for (int i = 0; i < numFlights; ++i) {
       int from, to, price;
       cin >> from >> to >> price;
       flights.push_back({from, to, price});
   }

   cout << "Enter the source city (src): ";
   cin >> src;

   cout << "Enter the destination city (dst): ";
   cin >> dst;

   cout << "Enter the maximum number of stops (k): ";
   cin >> k;

   // Create a Solution object and call the findCheapestPrice function
   Solution solution;
   int cheapestPrice = solution.findCheapestPrice(n, flights, src, dst, k);

   // Print the result
   if (cheapestPrice == -1) {
       cout << "No route from " << src << " to " << dst << " with at most " << k << " stops." << endl;
   } else {
       cout << "The cheapest price from " << src << " to " << dst << " with at most " << k << " stops is: " << cheapestPrice << endl;
   }

   return 0;
}
