// Two Sum Closest
// Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.
// Return the difference between the sum of the two integers and the target.

// 思路: two sum的变形，利用对顶型的双指针来做，因为用while循环，注意循环中止条件，判定时候分diff < o，以及else，防止两个指针不动，出现死循环

class Solution {
public:
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
    int twoSumCloset(vector<int>& nums, int target) {
        // Write your code here
        int min_ = INT_MAX;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int diff = target - (nums[i] + nums[j]);
            if (diff < 0) {
                j--;
            }
            else {
                i++;
            }
            if (abs(diff) < min_) {
                min_ = abs(diff);
            }
        }
        return min_;
    }
};