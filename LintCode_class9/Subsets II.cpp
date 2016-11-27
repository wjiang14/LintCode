// Subsets II
// Given a list of numbers that may has duplicate numbers, return all possible subsets
// Example
// If S = [1,2,2], a solution is:

// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

//又是dfs题

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here]
        vector<int> copy(S);
        vector<vector<int>> result;
        vector<int> sol;
        sort(copy.begin(), copy.end());
        result.push_back({});
        dfs(0, sol, result, copy);
        return result;
    }
    
    void dfs(int level, vector<int>& sol, vector<vector<int>>& result, const vector<int> s) {
        if(level == s.size()) {
            return;
        }
        
        for (int i = level; i < s.size(); i++) {
            if (i != 0 && s[i] == s[i - 1] && i > level) {
                continue;
            }
            sol.push_back(s[i]);
            result.push_back(sol);
            dfs(i + 1, sol, result, s);
            sol.pop_back();    
        }
    }
};
