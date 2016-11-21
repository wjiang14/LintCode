// Maximum Subarray
// Given an array of integers, find a contiguous subarray which has the largest sum.
// Example
// Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sum = 0;
        int max_ = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            max_ = max(sum, max_);
        }
        return max_;
    }
};