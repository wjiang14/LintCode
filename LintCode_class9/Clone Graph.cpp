Clone Graph

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

How we serialize an undirected graph:

Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
   1
  / \
 /   \
0 --- 2
     / \
     \_/
//可以用bfs，也可以用dfs，遍历一遍同时新建node(用hash表保存旧图到新图的映射)，遍历的同时建立新图.

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
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        //BFS
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashtab;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode* nodeCopy = new UndirectedGraphNode(node->label);
        hashtab[node] = nodeCopy;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* topNode = q.front();
            q.pop();
            for (auto neighbor : topNode->neighbors) {
                if (hashtab.find(neighbor) == hashtab.end()) {
                    UndirectedGraphNode* newNeighbor = new UndirectedGraphNode(neighbor->label);
                    hashtab[topNode]->neighbors.push_back(newNeighbor);
                    hashtab[neighbor] = newNeighbor;
                    q.push(neighbor);
                }
                else {
                    hashtab[topNode]->neighbors.push_back(hashtab[neighbor]);
                }
            }
        }
        return nodeCopy;
    }
};