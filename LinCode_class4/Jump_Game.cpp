// Jump Game

// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        //dynamic programing grasp; this is greedy
        int maxJump = 0;
        for (int i = 0; i < A.size(); i++) {
            if (maxJump < i || maxJump >= A.size() - 1) {
                break;
            }
            maxJump = max(maxJump, A[i] + i);
        }
        return maxJump >= (A.size() - 1)? true: false;
    }
};
