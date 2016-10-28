#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if(s == t){
            return true;
        }
        if (s.size() != t.size()){
            return false;
        }
        vector<string> result;
        string x;
        return dfs(0, x, s, t, result);
    }
    bool dfs(int index, string& x, string s, string t, vector<string>& result){
        if (x.size() == t.size()){
            result.push_back(x);
            for (int i = 0; i < result.size(); ++i)
            {
                if (result[i] == t)
                {
                    return true;
                }
            }
            return false;
        }
        
        for (int i = index; i < s.size(); i++){
            x.push_back(s[i]);
            dfs(i + 1, x, s, t, result);
            x.pop_back();
        }
    }
};

int main(){
    string s = "ab";
    string t = "ba";
    Solution result;
    cout << result.anagram(s, t);
    return 0;
}