// Jump_Game_II

// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.

动态规划算法为O(n^2), 贪心为O(n)

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        // vector<int> dp(A.size(), INT_MAX);
        // dp[0] = 0;
        // for (int i = 1; i < A.size(); i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (dp[j] != INT_MAX && j + A[j] >= i) {
        //             dp[i] = min(dp[j] + 1, dp[i]);
        //         }
        //     }
        // }
        // return dp.back();
        
        //greedy
        int n = A.size();
        int minstep = 0;
        int ldist = 0;
        int hdist = 0;
        if (n == 1) return 0;
        while(ldist <= hdist) {
            ++minstep;
            int lasthdist = hdist;
            for(int i = ldist; i <= lasthdist; ++i) {
                int possibledist = i + A[i];
                if (possibledist >= n-1)
                    return minstep;
                if (possibledist > hdist) {
                    hdist = possibledist;
                }
            }
            ldist = lasthdist + 1;
        }
        return 0;
    }
};