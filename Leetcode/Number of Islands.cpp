class Solution {
public:
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
    vector<vector<bool> > visited;
    int ans = 0;
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid){
        visited[i][j] = true;
        for (int k = 0; k < 4; k++){
            int x_new = i + x[k];
            int y_new = j + y[k];
            if (x_new < n && x_new >= 0 && y_new < m && y_new >= 0 && !visited[x_new][y_new] && grid[x_new][y_new] == '1') dfs(x_new, y_new, n, m, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j] && grid[i][j] == '1') dfs(i, j, n, m, grid), ans++;
            }
        }
        return ans;
    }
};