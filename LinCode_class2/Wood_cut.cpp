class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code her 
        int maxL = 0;
        for (int i = 0; i < L.size(); i++) {
            maxL = max(maxL, L[i]);
        }
        
        int start = 0, end = maxL;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isGreaterK(k, mid, L)) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (isGreaterK(k, end, L)) {
            return end;
        }
        if (isGreaterK(k, start, L)) {
            return start;
        }
        return 0;
    }
    
    bool isGreaterK(int k, int len, vector<int> L) {
        if (!len) {
            return false; //小心判定len不能为0
        }
        int sumL = 0;
        for (int i = 0; i < L.size(); i++) {
            sumL += L[i] / len;
        }
        return sumL >= k;
    }
};