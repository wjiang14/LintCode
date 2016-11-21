// Intersection of Two Arrays
// Given two arrays, write a function to compute their intersection.
// Example
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
// 三种方法: 1. hashtable。 2. sorting + 2point. 3. binary search; 把第一个排序，遍历第二个数组，找是否再第一个数组里出现过，
//然后丢到set里面去，最后转成vector; 另外stl里面还有个set_intersection函数?

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> result;
        unordered_map<int, int> hashtab;
        for (int i = 0; i < nums1.size(); i++) {
            hashtab[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            if (hashtab[nums2[i]]) {
                result.push_back(nums2[i]);
                hashtab.erase(nums2[i]);
            }
        }
        return result;
    }
};