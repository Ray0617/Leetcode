/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode clone(UndirectedGraphNode node, Map<Integer, UndirectedGraphNode> cache) {
        if (node == null)
            return null;
        if (!cache.containsKey(node.label)) {
            UndirectedGraphNode cloned = new UndirectedGraphNode(node.label);
            cache.put(node.label, cloned);
            for (UndirectedGraphNode neighbor : node.neighbors) {
                cloned.neighbors.add(clone(neighbor, cache));
            }
        }
        return cache.get(node.label);
    }
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        Map<Integer, UndirectedGraphNode> cache = new HashMap<Integer, UndirectedGraphNode>();
        return clone(node, cache); 
    }
}