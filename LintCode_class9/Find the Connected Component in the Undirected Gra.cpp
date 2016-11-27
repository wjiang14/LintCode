// Find the Connected Component in the Undirected Graph
// Find the number connected component in the undirected graph. Each node in the graph contains a label and a list 
// of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any 
// two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

// Example
// Given graph:

// A------B  C
//  \     |  | 
//   \    |  |
//    \   |  |
//     \  |  |
//       D   E
// Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int>> result;
        unordered_map<UndirectedGraphNode*, bool> visited;
        for (auto i : nodes) {
            visited[i] = false;
        }
        
        for (auto i : nodes) {
            if (!visited[i]) {
                bfs(i, result, visited);
            }
        }
        return result;
    }
    
    void bfs(UndirectedGraphNode* node, vector<vector<int>>& result, unordered_map<UndirectedGraphNode*, bool>& visited) {
        
        vector<int> tempSol;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        visited[node] = true;
        while (!q.empty()) {
            UndirectedGraphNode* temp = q.front();
            q.pop();
            tempSol.push_back(temp->label);
            int size = temp->neighbors.size();
            for (int i = 0; i < size; i++) {
                if (!visited[temp->neighbors[i]]) {
                    q.push(temp->neighbors[i]);
                    visited[temp->neighbors[i]] = true;
                }
            }
        }
        sort(tempSol.begin(), tempSol.end());
        result.push_back(tempSol);
        return;
    }
};