//Subarray Sum Closest
//Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.
//Example
//Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].
//思路: 跟Subarray Sum一样，这次要记录index，可以用vector<pair<int, int>>来记录，先放入(0,0)，数组的index从1开始，排序之后后面一项减去前面一项，
//得到结果之后index -1，因为我们的index从1开始，最小的放在结果的第一个值+1，大的为第二个结果.
//坑：第一次放(0, 0), 后面index从1开始。输出结果之前需要index - 1, 再排序，最小的放第一个，大的放第二个

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */

    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int, int>> sumResult;
        vector <int> result(2);

        int sum_ = 0;
        sumResult.push_back(make_pair(0, 0));
        for (int i = 0; i < nums.size(); i++) {
            sum_ += nums[i];
            sumResult.push_back(make_pair(sum_, i + 1));
        }

        sort(sumResult.begin(), sumResult.end());
        int ans = INT_MAX;
        for (int i = 1; i < sumResult.size(); i++) {
            if (sumResult[i].first - sumResult[i - 1].first < ans) {
                ans = sumResult[i].first - sumResult[i - 1].first;
                vector<int> temp = {sumResult[i].second - 1, sumResult[i - 1].second - 1};
                sort(temp.begin(), temp.end());
                result[0] = temp[0] + 1;
                result[1] = temp[1];
            }
        }
        return result;
    }
};
