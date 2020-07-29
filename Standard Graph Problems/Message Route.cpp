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

int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> v[n + 1];
    FOR0(i, m){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int parent[n + 1];
    int visited[n + 1];
    memset(visited, -1, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    visited[1] = 1;
    queue<int> qu;
    qu.push(1);
    while(!qu.empty()){
        x = qu.front();
        qu.pop();
        for (auto u: v[x]){
            if (visited[u] == -1){
                visited[u] = visited[x] + 1;
                parent[u] = x;
                qu.push(u);
            }
        }
    }
    if (visited[n] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << visited[n] << endl;
    vector<int> ans;
    while (parent[n]!=-1){
        ans.pb(n);
        n = parent[n];
    }
    ans.pb(1);
    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout << x << " ";
    // cout << ans << endl;
}