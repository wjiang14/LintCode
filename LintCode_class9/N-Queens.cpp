// N-Queens
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
// Example
// There exist two distinct solutions to the 4-queens puzzle:

// [
//   // Solution 1
//   [".Q..",
//    "...Q",
//    "Q...",
//    "..Q."
//   ],
//   // Solution 2
//   ["..Q.",
//    "Q...",
//    "...Q",
//    ".Q.."
//   ]
// ]

class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> results;
        vector<int> q(n);
        dfs(0, results, n, q);
        return results;
    }
    
    bool isPlaced(int i, int j, vector<int> q) {
        for (int k = 0; k < i; k++) {
            if (q[k] == j || abs(i - k) == abs(j - q[k])) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(int index, vector<vector<string>>& results, int n, vector<int>& q) {
        if (index == n) {
            results.push_back(print(q));
            return;
        }
        
        for(int i = 0; i < n; i ++) {
            if (isPlaced(index, i, q)) {
                q[index] = i;
                dfs(index + 1, results, n, q);
            }
        }
    }
    
    vector<string> print(vector<int>& q) {
        vector<string> sol(q.size(), string(q.size(), '.'));
        for (int i = 0; i < q.size(); i++) {
            sol[i][q[i]] = 'Q';
        }
        return sol;
    }
};
