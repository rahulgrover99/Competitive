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

vi graph[100001];
int in[100001];
int visited[100001];
int dp[100001];
int parent[100001];

void dfs(int node){
    // cout << node << endl;
    visited[node] = 1;
    for (auto u: graph[node]){
        in[u]--;
        if (visited[u] == 0){
            if (dp[u] < dp[node] + 1){
                dp[u] = max(dp[u], dp[node] + 1);
                parent[u] = node;
            }
            
            if (in[u]==0){
                // parent[u] = node;
                dfs(u);
            }
        }
    }
}

int main() {
    mst0(parent);
    mst0(visited);
    mst0(in);
    mst0(dp);
    int n, m, x, y;
    cin >> n >> m;
    FOR0(i, m){
        cin >> x >> y;
        if (y == 1) continue;
        graph[x].pb(y);
        in[y]++;
    }
    dp[1] = 1;
    parent[1] = -1;
    FOR1(i, n){
        if (in[i]==0 && visited[i] == 0) dfs(i);
    }
    // dfs(1);
    if (dp[n] == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dp[n] << endl;
    vi path;
    while(n!=-1){
        path.pb(n);
        n = parent[n];
    }
    reverse(path.begin(), path.end());
    for (auto x: path) cout << x << " ";
    cout << endl;

}