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
#define vi vector<int>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define sp <<" "<<
#define intmax 1e14
 
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}
 
int ans = 0;
vi v[100001];

int dfs(int node, int par){
    int tot = 0;
    for (auto x: v[node]){
        if (x == par) continue;
        tot += dfs(x, node);
    }
    // cout << node sp tot << endl;
    if (tot%2==1){
        ans++;
        return 0;
    }
    
    return tot + 1;
}

int main(){
    int n, x, y;
    cin >> n;
    FOR0(i, n - 1){
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    dfs(1 , -1);
    cout << ans - 1 << endl;
}