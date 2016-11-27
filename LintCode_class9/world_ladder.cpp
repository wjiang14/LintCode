// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary

// Example
// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//利用bfs找最短距离，问题是怎么判定下一个level，在大数据条件下利用26个字母比较快，这样一次判定为26*w(w为word长度)，每次bfs下一个level就不用扫描
//整个dict了。为了防止走回头路，每次判定完要在dict中删除word，开始的时候要在dict中插入endword。


class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        dict.insert(end);
        while (!q.empty()) {
            string currWord = q.front().first;
            int len = q.front().second;
            q.pop();
            if (end == currWord) {
                return len;
            }
            vector<string> Level = nextLevel(currWord, dict);
            for (int i = 0; i < Level.size(); i++) {
                q.push(make_pair(Level[i], len + 1));
            }
        }
        return 0;
    }
    
    vector<string> nextLevel(string target, unordered_set<string> &dict) {
        vector<string> outputLevel;
        for (int i = 0; i < target.size(); i++) {
            char c = target[i];
            for (int j = 0; j < 26; j++) {
                if (c == 'a' + j) {
                    continue;
                }
                target[i] = 'a' + j;
                if (dict.count(target)) {
                    outputLevel.push_back(target);
                    dict.erase(target);
                }
            }
            target[i] = c;
        }
        return outputLevel;
    }
};