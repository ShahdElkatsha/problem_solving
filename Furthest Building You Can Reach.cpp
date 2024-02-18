//Array , Greedy , Heap (Priority Queue)

/*You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.*/

#include <iostream>
#include <vector>
#include <queue> // Include the queue header file
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        // for storing bricks used in each step in decreasing order (Max at top)
        priority_queue<int> pQueue;
        int i = 0, high_diff = 0;
        
        for (i = 0; i < heights.size() - 1; ++i) {
            high_diff = heights[i + 1] - heights[i]; // height difference
            
            if (high_diff <= 0) continue; // means no additional bricks required to climb to next building
            
            bricks -= high_diff;
            pQueue.push(high_diff);
            
            if (bricks < 0) { // available bricks not enough to climb to next building
                if (ladders > 0) { // if ladders available
                    bricks += pQueue.top(); // use a ladder from the priority queue
                    pQueue.pop();
                    ladders--; 
                } else {
                    break; // no more ladders, can't proceed further
                }
            }
        }
        return i; // return the furthest index reached

      // priority_queue<int> ladder_gaps;// negative height differences between buildings

        // for (int i = 0; i < heights.size() - 1; ++i) {
        //     int gap = heights[i + 1] - heights[i];
        //     if (gap > 0) {
        //         ladder_gaps.push(-gap);
        //         if (ladder_gaps.size() > ladders) {
        //             bricks += ladder_gaps.top();
        //             ladder_gaps.pop();
        //             if (bricks < 0) {
        //                 return i;
        //             }
        //         }
        //     }
        // }

        // return heights.size() - 1;

    }
};


int main() {
    Solution solution;
    
    // Test case 1
    vector<int> heights1 = {4,2,7,6,9,14,12};
    int bricks1 = 5, ladders1 = 1;
    cout << "Test case 1: " << solution.furthestBuilding(heights1, bricks1, ladders1) << endl;

    // Test case 2
    vector<int> heights2 = {4,3,1,1,3,3,2};
    int bricks2 = 3, ladders2 = 1;
    cout << "Test case 2: " << solution.furthestBuilding(heights2, bricks2, ladders2) << endl;

    return 0;
}
