// Combination Sum
// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.

// For example, given candidate set 2,3,6,7 and target 7, 
// A solution set is: 
// [7] 
// [2, 2, 3] 

//dfs题

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> result;
        vector<int> sum;
        if (candidates.size() == 0 || target <= 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        dfs(0, result, target, candidates, sum);
        return result;
    }
    
    void dfs(int level, vector<vector<int>>& result, int target, vector<int>& candidates, vector<int>& sum) {
        
        if (target == 0) {
            result.push_back(sum);
            return;
        }
        else if(target < 0){
            return;
        }
        
        for (int i = level; i < candidates.size(); i ++) {
            if (i != 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            target -= candidates[i];
            sum.push_back(candidates[i]);
            dfs(i, result, target, candidates, sum);
            sum.pop_back();
            target += candidates[i];
        }
    }
};