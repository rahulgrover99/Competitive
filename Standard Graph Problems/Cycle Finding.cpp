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

int n, m, v = 1;
vector<edge> e;
const ll INF = 1000000000;

void solve()
{
    vector<ll> d(n + 1, INF);
    d[v] = 0;
    vector<ll> p(n + 1, -1);
    ll x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j){
            // if (i == n - 1) cout << e[j].b sp e[j].a sp d[e[j].a] << endl;
            // if (d[e[j].a] < INF){
                // if (i == n - 1) cout << e[j].b sp e[j].a << endl;
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
            // }
        }
    }

    if (x == -1)
        cout << "NO" << endl;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "YES\n";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    ll a, b, c;
    FOR0(i, m){
        cin >> a >> b >> c;
        e.pb({a, b, c});
    }
    solve();

}

/*

4 5
1 1 0
2 1 3
2 2 -1
3 4 3
4 2 6

*/
