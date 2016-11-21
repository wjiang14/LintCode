//Two Sum
//Given an array of integers, find two numbers such that they add up to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.
//Example
//numbers=[2, 7, 11, 15], target=9
//return [1, 2]

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        write your code here
        unordered_map<int, int> hashtab;
        vector<int> result(2, -1);
        if (nums.size() == 0) {
            return result;
        }
        
        hashtab[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (hashtab[target - nums[i]]) {
                result[0] = hashtab[target - nums[i]];
                result[1] = i + 1;
            }
            else {
                hashtab[nums[i]] = i + 1;
            }
        }
        return result;
        
    }
};
