//Array , Dynamic Programming , Matrix

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // int pass1 = collectCherries(grid , rows , cols , 0 , 0 , cols-1 , 0);
        // int pass2 = collectCherries(grid , rows , cols , 0 , cols-1 , cols-1 , 0);
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        return dfs(grid, dp, 0, 0, cols - 1);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col1, int col2 ){

        // If current row is out of bounds return 0
        if (row == grid.size()) return 0;

        // If the value has already been calculated, return it
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int cherries = 0;
        // Add cherries collected by robots at current cell
        cherries += grid[row][col1];
        if (col1 != col2){
            cherries += grid[row][col2];
        } 

        int maxCherries = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int z = -1; z <= 1; ++z) {

                int newcol1 = col1 + i;
                int newcol2 = col2 + z;
                // Check if new positions are within bounds
                if (newcol1 >= 0 && newcol1 < grid[0].size() && newcol2 >= 0 && newcol2 < grid[0].size()){
                    maxCherries = max( maxCherries , dfs(grid, dp, row+1,  newcol1,  newcol2) );
                }
            }
        }
        // Update dp with maximum cherries collected at current cell
        dp[row][col1][col2] = cherries + maxCherries;

        return dp[row][col1][col2];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}
    };

    int maxCherries = solution.cherryPickup(grid);
    cout << "Maximum cherries collected: " << maxCherries << endl;

    return 0;
}
