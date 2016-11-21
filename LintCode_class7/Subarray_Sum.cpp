// Subarray Sum
// Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
// Example
// Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

// 思路: 遍历整个数组，求和存入hash table，如果再次出现，则说明之间这一段array和为0，此方法可以推广至subarray之和为target数。
// 坑: 如果第一个数为0呢？因此在hash table里最好先存入<0, -1>，返回值则变为了<hashtab[sum] + 1, i>，这是值得注意的一点。

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        vector<int> result;
        unordered_map<int, int> hashtab;
        
        int sum = 0;
        hashtab[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hashtab.find(sum) != hashtab.end()) {
                result.push_back(hashtab[sum] + 1);
                result.push_back(i);
                return result;
            }
            else {
                hashtab[sum] = i;
            }
        }
        return result;
    }
};