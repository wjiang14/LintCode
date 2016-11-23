// Longest Common Subsequence

// Given two strings, find the longest common subsequence (LCS).
// Your code should return the length of LCS.

// Clarification
// What's the definition of Longest Common Subsequence?
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
// http://baike.baidu.com/view/2020307.htm
// Example
// For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.

// For "ABCD" and "EACB", the LCS is "AC", return 2.

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[j - 1] == B[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
