vector< int > rows{-1, 0, 0, 1};
vector< int > cols{0, -1, 1, 0};

vector< vector< bool > > visited{};


void dfs(int i, int j, int n, int m, vector<string> A){
for(int k = 0; k < 4; ++k){
        if(i + rows[k] >= 0 and i + rows[k] < n and j + cols[k] >= 0 and j + cols[k] < m and A[i + rows[k]][j + cols[k]] == 'X' and !visited[i + rows[k]][j + cols[k]]){
            visited[i + rows[k]][j + cols[k]] = true;
            dfs(i + rows[k], j + cols[k], n, m, A);
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    if (n==0) return 0;
    int m = A[0].size();
    visited.clear();
    visited.resize(n);
    for(int i = 0; i < n; ++i) visited[i].resize(m);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j] and A[i][j] == 'X'){
                visited[i][j] = true;
                dfs(i, j, n, m, A);
                ++ans;
            }
        }
    }
    
    return ans;
    
}
