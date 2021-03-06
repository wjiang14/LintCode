// Longest_Common_Substring

// Given two strings, find the longest common substring.
// Return the length of it.
// Example
// Given A = "ABCD", B = "CBCE", return 2.

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int ans = 0;
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < B.size(); j++){
                int l = 0;
                while (i + l < A.size() && j + l < B.size() && A[i + l] == B[j + l]){
                    l += 1;
                }
                if (l > ans){
                    ans = l;
                }
            }
        }
        return ans;
    }
};
