// Longest_Increasing_Subsequence

// Given a sequence of integers, find the longest increasing subsequence (LIS).
// You code should return the length of the LIS.
// 经典问题，此题必须会。可以用滚动数组减小到1维，动态规划算法为O(n^2)。另外还有一种利用二分搜索达到O(n)的算法，用k的额外空间，k为最长子序列长度。
// 可以用find代替，不用自己手动写二分搜索

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        vector<int> dp(nums.size());
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i]: dp[j] + 1; 
                }
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
