// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Example
// Given [1, 0, 1, 2], sort it in-place to [0, 1, 1, 2].

//思路: 类似quick sort
//坑: 用while循环而不用for循环，因为其事不知道循环长度的。另外因为k从0开始走，循环的时候可以k++，但是对于k == 2，只能j--，不能k++，因为如果换过来的是0
//就跪啦！！，最后一种情况就直接k++

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int k = 0, i = 0, j = nums.size() - 1;
        while (k <= j) {
            if (nums[k] == 0) {
                swap(nums[i++], nums[k++]);
            }
            else if (nums[k] == 2) {
                swap(nums[k], nums[j--]);
            }
            else {
                k++;
            }
        }
        return;
    }
};