// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.\

// Example
// Given s = "aab", return:

// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;
        vector<vector<bool>> isPali (n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>=j-1 || isPali[i+1][j-1]) && s[i]==s[j])
                    isPali[i][j] = true;
            }
        }
        dfs(0, res, path, s, isPali);
        return res;
    }
    
    void dfs(int level, vector<vector<string>>& res, vector<string>& path, string s, const vector<vector<bool>> isPali) {
        if (level == s.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = level; i < s.size(); i++) {
            if (isPali[level][i]) {
                path.push_back(s.substr(level, i - level + 1));
                dfs(i + 1, res, path, s, isPali);
                path.pop_back();
            }
        }
    }
};