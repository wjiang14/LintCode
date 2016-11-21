//Partition Array
//Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
//All elements < k are moved to the left
//All elements >= k are moved to the right
//Return the partitioning index, i.e the first index i nums[i] >= k.

//Example
//If nums = [3,2,2,1] and k=2, a valid answer is 1.

//就是一个quick sort。。。。

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] < k) {
                swap(nums[i++], nums[j]);
            }
        }
        return i;
    }
};