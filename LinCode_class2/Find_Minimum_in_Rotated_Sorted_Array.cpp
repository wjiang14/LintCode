class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int start = 0, end = nums.size() - 1;
        int target = nums[end];
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[start] <= target) {
            return nums[start];
        }
        else {
            return nums[end];
        }
    }
};