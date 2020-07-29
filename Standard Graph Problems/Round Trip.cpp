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

bool visited[100001];
int parent[100001];
vector<int> v[100001];
bool chk = false;
vector<int> ans;

void dfs(int node, int par){
    visited[node] = true;
    for (auto x: v[node]){
        if (x == par) continue; 
        if (!visited[x]){
            // cout << x << endl;
            parent[x] = node;
            dfs(x, node);
            // cout << x << endl;
        }
        else if(!chk) {
            chk = true;
            // cout << node << " " << x << endl;
            ans.push_back(node);
            // cout << ans[0] << endl;
            int start = node;
            // cout << x << endl;
            while(node!=x){
                // cout << node << " " << parent[node] << endl;
                node = parent[node];
                ans.push_back(node);
            }
            // cout << start << endl;
            ans.push_back(start);
            // for (auto x : ans) cout << x << " ";
        }
    }
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    
    FOR0(i, m){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    FOR1(i, n) {
        if (!visited[i]) dfs(i, -1);
    }
    if (!chk) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans.size() << endl;
    FOR0(i, ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}