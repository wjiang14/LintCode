Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        vector<vector<int>> result(triangle); // build a copy of triangle
        //bottom up
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j < i + 1; j++){
                result[i][j] = result[i][j] + min(result[i + 1][j], result[i + 1][j + 1]);
            }
        }
        return result[0][0];
    }
};
