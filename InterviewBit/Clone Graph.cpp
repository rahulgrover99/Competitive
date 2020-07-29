/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;


UndirectedGraphNode * rec(UndirectedGraphNode *node){
    if (!node) return nullptr;
    if (mp.find(node) == mp.end()){
        mp[node] = new UndirectedGraphNode(node->label);
        for (auto neighbours: node->neighbors){
            mp[node]->neighbors.push_back(rec(neighbours));
        }
    }
    return mp[node];
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    mp.clear();
    return rec(node);
}




