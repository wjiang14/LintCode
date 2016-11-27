// Six Degrees

// Six degrees of separation is the theory that everyone and everything is six or fewer steps away, by way of introduction, from any other person in the world, so that a chain of "a friend of a friend" statements can be made to connect any two people in a maximum of six steps.

// Given a friendship relations, find the degrees of two people, return -1 if they can not been connected by friends of friends.

// Example
// Gien a graph:

// 1------2-----4
//  \          /
//   \        /
//    \--3--/
// {1,2,3#2,1,4#3,1,4#4,2,3} and s = 1, t = 4 return 2

// Gien a graph:

// 1      2-----4
//              /
//            /
//           3
// {1#2,4#3,4#4,2,3} and s = 1, t = 4 return -1

//思路:bsf，就是要熟悉，下一个节点入队之前要先check是否被访问过了，可以建立一个hash table，key为节点，value为距离
//坑: 返回距离的时候有两种选择，1，可以在入队的时候判断，此时应该是step + 1，因为step的值还没有被更新。并且前面要考虑(s == t)。2，出对的时候判断，
//这时应该返回step，并且不用检查s == t，这种情况已经包含了s == t的情况。

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph a list of Undirected graph node
     * @param s, t two Undirected graph nodes
     * @return an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph,
                   UndirectedGraphNode* s,
                   UndirectedGraphNode* t) {
        // Write your code here
        
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, int> visited;
        q.push(s);
        visited[s] = 0;
        
        while (!q.empty()) {
            UndirectedGraphNode* topNode = q.front();
            q.pop();
            int step = visited[topNode];
            int size = topNode->neighbors.size();
            if (topNode == t) {
                    return step;
            }
            for (int i = 0; i < size; i++) {
                if (visited.find(topNode->neighbors[i]) != visited.end()) {
                    continue;
                }
                
                q.push(topNode->neighbors[i]);
                visited[topNode->neighbors[i]] = visited[topNode] + 1;
            }
        }
        return -1;
    }
};