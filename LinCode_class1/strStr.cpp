
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    // 没啥好说的，就是simulation，但是要提前判断source到没到字符末尾, 双指针大法，只不过双指针用在了两个字符串上
    int strStr(const char *source, const char *target) {
        
        if (source == NULL || target == NULL){
            return -1;
        }

        int i = 0;
        while (*target != '\0' ){
            if (*source == '\0') //先判断source到没到末尾;
            {
                return -1;
            }
            if (*target == *source){
                target++;
                source++;
            }
            else{
                source++;
                i++;
            }
        }
        return i;
    }
};

int main(){
    char s[12] = "abcdabcdefg";
    char t[4] = "bcd";
    Solution sol;
    cout << sol.strStr(s, t);
    return 0;
}