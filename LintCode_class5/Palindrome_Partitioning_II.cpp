// Palindrome_Partitioning_II

// Given a string s, cut s into some substrings such that every substring is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

// Example
// Given s = "aab",
// Return 1 since the palindrome partitioning ["aa", "b"] could be produced using 1 cut.

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n = s.size();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j])
                    isPal[i][j] = true;
            }
        }
        
        vector<int> dp(n+1,INT_MAX);
        dp[0] = -1;
        for(int i=1; i<=n; i++) {
            for(int j=i-1; j>=0; j--) {
                if(isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};

