//Median of two Sorted Arrays
//There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
//Example
//Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

//Given A=[1,2,3] and B=[4,5], the median is 3.

//1. 可以先merge，2. divide & conquer
//回头再看

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        // write your code here
        int sum = nums1.size() + nums2.size();
        double ret;
        
        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = ((findKth(nums1, nums2, 0, 0, sum / 2)) +
                    findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
    
    double findKth(vector<int>& A, vector<int>& B, int A_st, int B_st, int k) {
        // 边界情况，任一数列为空
        if (A_st >= A.size()) {
            return B[B_st + k - 1];
        }
        if (B_st >= B.size()) {
            return A[A_st + k - 1];
        }
        // k等于1时表示取最小值，直接返回min
        if (k == 1) return min(A[A_st], B[B_st]);
        int A_key = A_st + k / 2 - 1 >= A.size() ? INT_MAX : A[A_st + k / 2 - 1];
        int B_key = B_st + k / 2 - 1 >= B.size() ? INT_MAX : B[B_st + k / 2 - 1];
        if (A_key < B_key){
            return findKth(A, B, A_st + k / 2, B_st, k - k / 2);
        } else {
            return findKth(A, B, A_st, B_st + k / 2, k - k / 2);
        }
        
    }
};
