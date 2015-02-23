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
    UndirectedGraphNode* clone(UndirectedGraphNode *node, map<int, UndirectedGraphNode*>& cache) {
        if (!node)
            return 0;
        if (cache.find(node->label) == cache.end()) {
            UndirectedGraphNode* cloned = new UndirectedGraphNode(node->label);
            cache[node->label] = cloned;
            for (int i = 0; i < node->neighbors.size(); i++) {
                cloned->neighbors.push_back( clone(node->neighbors[i], cache) );
            }
        }
        return cache[node->label];
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> cache;
        return clone(node, cache);
    }
};