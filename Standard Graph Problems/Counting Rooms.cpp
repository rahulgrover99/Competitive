#include<bits/stdc++.h>
#define FOR0(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
#define pi pair<ll,ll>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define mst0(x) memset(x,0,sizeof(x));
#define vi vector<ll>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define sp <<" "<<
#define intmax 1e14

ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};
vector<vector<bool> > visited;
int ans = 0;
void dfs(int i, int j, int n, int m, string grid[]){
    visited[i][j] = true;
    for (int k = 0; k < 4; k++){
        int x_new = i + x[k];
        int y_new = j + y[k];
        if (x_new < n && x_new >= 0 && y_new < m && y_new >= 0 && !visited[x_new][y_new] && grid[x_new][y_new] == '.') dfs(x_new, y_new, n, m, grid);
    }
}

int numIslands(string grid[], int n) {
    ans = 0;
    if (n == 0) return 0;
    int m = grid[0].size();
    visited.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && grid[i][j] == '.') dfs(i, j, n, m, grid), ans++;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s[n];
    FOR0(i, n) cin >> s[i];
    cout << numIslands(s, n);

}