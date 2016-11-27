// Permutations II
// Given a list of numbers with duplicate number in it. Find all unique permutations.
// Example
// For numbers [1,2,2] the unique permutations are:

// [
//   [1,2,2],
//   [2,1,2],
//   [2,2,1]
// ]

//dfs题

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> result;
        vector<int> sol;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(visited, sol, result, nums);
        return result;
    }
    
    void dfs(vector<bool>& visited, vector<int>& sol, vector<vector<int>>& result, vector<int>& nums) {
        if (sol.size() == nums.size()) {
            result.push_back(sol);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == false) {
                    continue;
                }
                sol.push_back(nums[i]);
                visited[i] = true;
                dfs(visited, sol, result, nums);
                visited[i] = false;
                sol.pop_back();
            }
        }
    }
};