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
int visited[100001];
vector<int> v[100001];
bool chk = true;
void dfs(int node, int team){
    visited[node] = team;
    for (auto x: v[node]){
        // cout << x << endl;
        if (visited[x] == -1){
            dfs(x, 1-team);
        }
        else{
            if (visited[x] != 1-team) chk = false;
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
    
    memset(visited, -1, sizeof(visited));

    FOR1(i, n) {
        if (visited[i]==-1) dfs(i, 0);
    }
    if (!chk) {
        cout << "IMPOSSIBLE" << endl;
        // return 0;
    }
    FOR1(i, n){
        cout << visited[i] + 1 << " ";
    }
    cout << endl;
}