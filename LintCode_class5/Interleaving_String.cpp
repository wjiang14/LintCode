// Interleaving_String

// Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
// Example
// For s1 = "aabcc", s2 = "dbbca"
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        bool interleave[s1.length() + 1][s2.length() + 1];
        interleave[0][0] = true;
        for (int i = 1; i <= s1.length(); i++) {
            interleave[i][0] = interleave[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i <= s2.length(); i++) {
            interleave[0][i] = interleave[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                interleave[i][j] = false;
                if (s1[i - 1] == s3[i + j - 1]) {
                    interleave[i][j] = interleave[i][j] || interleave[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    interleave[i][j] = interleave[i][j] || interleave[i][j - 1];
                }
            }
        }
        
        return interleave[s1.length()][s2.length()];
    }
};