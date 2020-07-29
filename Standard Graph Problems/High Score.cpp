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

struct edge
{
    ll a, b, cost;
};
int main(){
    // freopen("test_input.txt","r",stdin);
	// freopen("test_output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    // ll a, b, c;
    edge v[n + 1];
    FOR0(i, m){
        cin >> v[i].a >> v[i].b >> v[i].cost;
    }
    vector<ll> d(n + 1, -1e14);
    d[1] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[v[j].a] != -1e14 && d[v[j].a] + v[j].cost > d[v[j].b])
                d[v[j].b] = max(d[v[j].b], d[v[j].a] + v[j].cost);

    ll tmp = d[n];
    
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[v[j].a] != -1e14 && d[v[j].a] + v[j].cost > d[v[j].b])
                d[v[j].b] = max(d[v[j].b], d[v[j].a] + v[j].cost);

    if (d[n]!=tmp) cout << -1 << endl;
    else cout << d[n] << endl;
}