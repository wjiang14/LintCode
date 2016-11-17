// Minimum Path Sum
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(grid);
        for (int i = 1; i < n; i++) {
            dp[0][i] += dp[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] += dp[i - 1][0];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + dp[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
