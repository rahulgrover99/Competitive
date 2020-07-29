class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        vector<int> path;
        path.push_back(0);
        backtrack(path, ans, graph, 0);
        return ans;
    }
    
    void backtrack(vector<int> &path, vector<vector<int> > &ans, vector<vector<int> >& graph, int cur){
        if (cur == graph.size() - 1){
            ans.push_back(path);
            return;
        }
        for (auto x: graph[cur]){
            path.push_back(x);
            backtrack(path, ans, graph, x);
            path.pop_back();
        }
        
    }
};