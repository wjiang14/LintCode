class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result;
        if (A.size() == 0) {
            return result;
        }
        int i = findleft(A, 0, A.size() - 1, target);
        int j = findright(A, 0, A.size() - 1, target);
        result.push_back(i);
        result.push_back(j);
        return result;
    }
    // use binary O(logn)
    int findleft(vector<int>& A, int start, int end, int target) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = target;
            }
            else if (A[mid] > target) {
                end = target;
            }
            else {
                start = target;
            }
        }
        if (A[start] = target) {
            return start;
        }
        if (A[end] = target) {
            return end;
        }
        return -1;
    }
    
    int findright(vector<int>& A, int start, int end, int target) {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                start = target;
            }
            else if (A[mid] > target) {
                end = target;
            }
            else {
                start = target;
            }
        }
        if (A[end] = target) {
            return end;
        }
        if (A[start] = target) {
            return start;
        }
        return -1;
    }
};