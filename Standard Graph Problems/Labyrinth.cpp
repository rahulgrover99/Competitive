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
vector<vector<int> > visited;
vector<vector<pi> > parent;
void bfs(int sx, int sy, int n, int m, string grid[]){
    visited[sx][sy] = 0;
    queue<pi> qu;
    qu.push({sx, sy});
    while(!qu.empty()){
        auto tmp = qu.front();
        qu.pop();
        int i = tmp.ff;
        int j = tmp.ss;
        // cout << i << " " << j << endl;
        for (int k = 0; k < 4; k++){
            int x_new = i + x[k];
            int y_new = j + y[k];
            if (x_new < n && x_new >= 0 && y_new < m && y_new >= 0 && visited[x_new][y_new] == INT_MAX && grid[x_new][y_new] != '#') {
                qu.push({x_new, y_new});
                parent[x_new][y_new] = {i, j};
                visited[x_new][y_new] = visited[i][j] + 1;
            }
        }
    }
    
}

void travel(string grid[], int n) {

    int m = grid[0].size();
    visited.resize(n, vector<int>(m, INT_MAX));
    parent.resize(n, vector<pi>(m, {-1, -1}));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 'A') bfs(i, j, n, m, grid);
        }
    }

}

string find_path(int i, int j){
    string ans = "";
    while(parent[i][j] != mp(-1LL, -1LL)){

        auto tmp = parent[i][j];

        if (tmp.ff == i && tmp.ss == j + 1) ans+="L";
        else if (tmp.ff == i && tmp.ss == j - 1) ans += "R";
        else if (tmp.ff == i + 1) ans += "U";
        else ans += "D";

        i = tmp.ff;
        j = tmp.ss;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    int n, m;
    cin >> n >> m;
    string s[n];
    FOR0(i, n) cin >> s[i];
    travel(s, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == 'B') {
                if (visited[i][j] != INT_MAX){
                    cout << "YES" << endl;
                    cout << visited[i][j] << endl;
                    cout << find_path(i, j) << endl;
                }
                else {
                    cout << "NO" << endl;
                }
                return 0;
            }
        }
    }
}