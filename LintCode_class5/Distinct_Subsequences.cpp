
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences of T in S.

// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Example
// Given S = "rabbbit", T = "rabbit", return 3.

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        int n = S.size(), m = T.size();
        vector<int> dp(n+1, 1);
        
        for(int i=1; i<=m; i++) {
            int upLeft = dp[0];
            dp[0] = 0;
            for(int j=1; j<=n; j++) {
                int temp = dp[j];
                dp[j] = dp[j-1];
                if(S[j-1]==T[i-1]) dp[j] += upLeft;
                upLeft = temp;
            }
        }
        
        return dp[n];

    }
};
