Topological Sorting
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Example
For graph as follow:

picture

The topological order can be:

[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...

//就是要找一个入度为0的点，然后扣掉，放到数组里面，再重复找入度为0的点...
//先遍历数组统计入度，然后dfs, bfs都可以。

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        //DFS,统计入度为0的点作为递归的出发点
        map<DirectedGraphNode*, int> countrd;
        vector<DirectedGraphNode*> ans;
        for(int i = 0; i < graph.size(); i++)
            for(int j = 0; j < graph[i]->neighbors.size(); j++)
                 if (countrd.find(graph[i]->neighbors[j]) == countrd.end())
                    countrd[graph[i]->neighbors[j]] = 1;
                 else
                    countrd[graph[i]->neighbors[j]] += 1;

        for(int i = 0; i < graph.size(); i++)
            if(countrd[graph[i]] == 0)
                dfs(graph[i], ans, countrd, graph);
        return ans;
    }
    
    void dfs(DirectedGraphNode* i, vector<DirectedGraphNode*> &ans, map<DirectedGraphNode*, int> &countrd,vector<DirectedGraphNode*> graph)         
    {
    	ans.push_back(i);
        countrd[i]--;
        for(int j = 0; j < i->neighbors.size(); j++) {
		        countrd[i->neighbors[j]]--;
                if(countrd[i->neighbors[j]] == 0)
		        dfs(i->neighbors[j], ans, countrd, graph);
	    }
    }
};