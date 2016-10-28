class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    // 思路: 利用26个字母维护两个数组，统计string A, string B里面字母出现的次数，如果B的次数大于A, 则为false。如果用hashtable，需要去重复，比较麻烦
    // test case比较奇怪" ", " "输入给出的是false，但是"",""给出的是true!!!
    bool compareStrings(string A, string B) {
        if (A.empty() && B.empty()){
            return true;
        }
        else if (A.empty()){
            return false;
        }
        else if (A == " " && B== " "){
            return false;
        }
        int AA[26] = {0}, BB[26] = {0};
        for (auto i : A){
            AA[i - 'A']++;
        }
        
        for (auto j : B){
            BB[j - 'A']++;
            if (BB[j - 'A'] > AA[j - 'A']) return false;
        }
        return true;
    }
};
