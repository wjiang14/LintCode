// k Sum II
// Given n unique integers, number k (1<=k<=n) and target.
// Find all possible k integers where their sum is target.

// Example
// Given [1,2,3,4], k = 2, target = 5. Return:

// [
//   [1,4],
//   [2,3]
// ]

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> solution;
        dfs(0, solution, result, A, target, k);
        return result;
    }
    
    void dfs(int level, vector<int>& solution, vector<vector<int>>& result, const vector<int> A, int target, int k) {
        if (solution.size() == k && target == 0) {
            result.push_back(solution);
            return;
        }
        
        for (int i = level; i < A.size(); i++) {
            if (A[i] <= target) {
                target -= A[i];
                solution.push_back(A[i]);
                dfs(i + 1, solution, result, A, target, k);
                solution.pop_back();
                target += A[i];
            }
        }
    }
};
