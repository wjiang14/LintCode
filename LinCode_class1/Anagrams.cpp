#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        //use hashtable
        vector<string> result;
        unordered_map<string, int> hashtab;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            ++hashtab[s];
        }
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (hashtab[s] > 1){
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};


int main(){
    vector<string> var({"tea","and","ate","eat","den"});
    vector<string> s;
    Solution sol;
    s = sol.anagrams(var);
    for (auto i : s)
    {
        cout << i << " ";
    }
    return 0;
}
