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


bool cycle = false;
int visited[100001];
vi graph[100001];
int parent[100001];
vi path;

void dfs(int node){
    // cout << node sp parent[node] << endl;
    visited[node] = 1;
    for (auto u: graph[node]){
        if (visited[u] == 0){
            parent[u] = node;
            dfs(u);
        }
        else if (visited[u] == 1){
            cycle = true;
            if (path.empty()){
                path.pb(u);
                path.pb(node);
                int start = u;
                u = parent[node];
                // cout << u sp parent[u] << endl;
                while(start != u){
                    
                    path.pb(u);
                    u = parent[u];
                }
                path.pb(start);
            }
        }
    }

    visited[node] = 2;
}

int main(){
    mst0(parent);
    mst0(visited);
    int n, m;
    cin >> n >> m;
    int x, y;
    FOR0(i, m){
        cin >> x >> y;
        graph[x].pb(y);
    }
    FOR1(i, n){
        if (visited[i] == 0){
            dfs(i);
        }
        if (cycle){
            cout << path.size() << endl;
            reverse(path.begin(), path.end());
            for (auto x: path) cout << x << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}