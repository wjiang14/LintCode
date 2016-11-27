// N-Queens II
// Follow up for N-Queens problem.
// Now, instead outputting board configurations, return the total number of distinct solutions.
// Example
// For n=4, there are 2 distinct solutions.

//比N-Queen还简单

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        int totalN = 0;
        vector<int> q(n);
        dfs(0, totalN, q, n);
        return totalN;
    }
    
    void dfs(int level, int& totalN, vector<int>& q, int n) {
        if (level == n) {
            totalN++;
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isPlaced(level, i, q)) {
                q[level] = i;
                dfs(level + 1, totalN, q, n);
            }
        }
    }
    
    bool isPlaced(int k, int j, vector<int> q) {
        for (int i = 0; i < k; i++) {
            if (q[i] == j || abs(k - i) == abs(j - q[i])) {
                return false;
            }
        }
        return true;
    }
};
