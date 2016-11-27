// String Permutation II
// Given a string, find all permutations of it without duplicates.

// Example
// Given "abb", return ["abb", "bab", "bba"].

// Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].

class Solution {
public:
    /**
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) {
        // Write your code here
        vector<bool> isvisited(str.size(), false);
        vector<string> results;
        string permutation;
        if (str.size() == 0) {
            results.push_back("");
            return results;
        }
        sort(str.begin(), str.end());
        dfs(results, permutation, str, isvisited);
        return results;
    }
    
    void dfs(vector<string>& results, string& permutation, string& str, vector<bool>& isvisited) {
        if (permutation.size() == str.size()) {
            results.push_back(permutation);
            return;
        }
        
        for (int i = 0; i < str.size(); i ++) {
            if (!isvisited[i]) {
                if (i != 0 && str[i] == str[i - 1] && !isvisited[i - 1]) {
                    continue;
                }
                permutation.push_back(str[i]);
                isvisited[i] = true;
                dfs(results, permutation, str, isvisited);
                isvisited[i] = false;
                permutation.pop_back();
            }
        }
    }
};