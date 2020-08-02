class TreeAncestor {
public:
    int n, l;
    vector<vector<int>> adj;
    vector<vector<int>> up;

    void dfs(int v, int p)
    {
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            if (up[v][i-1] == -1) up[v][i] = -1;
            else up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

    }
    TreeAncestor(int n, vector<int>& parent) {
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        adj.assign(n + 1, vector<int>());
        for (int i= 1; i < parent.size(); i++){
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0, -1);
    }
    
    int getKthAncestor(int node, int k) {
        int cnt = 0;
        while(k > 0){
            if(k&1){
                node = up[node][cnt];
            }
            cnt++;
            k /= 2;
            if(node == -1){
                break;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */