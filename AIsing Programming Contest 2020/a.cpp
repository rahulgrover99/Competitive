#include<bits/stdc++.h>
#define FOR0(i,n) for(ll i=0;i<n;i++)
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
ll mod = 1e9 + 7;

ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

vector<vi> adj;
ld ans;
ll n, a, b, x, tme;
ll dp[500001][21];
vi dp1, dp2;
ll time_in[500001], time_out[500001];
ll timer, l = 20;

ll bin_lift(ll cur, ll node){
	ll res = cur, cnt = 0;
	while(node) {
		if (node&1) res = dp[res][cnt];
		node/=2;
		cnt++;
	}
	return res;
}
void solve(ll cur, ll par){
	for (auto c : adj[cur]){
		if (c == par) continue;
		solve(c, cur);
	}
	dp1[bin_lift(cur, a)] += dp1[cur];
	dp2[bin_lift(cur, b)] += dp2[cur];
}

void dfs(ll v, ll p){
    time_in[v] = ++timer;
    dp[v][0] = p;
    for (int i = 1; i <= l; ++i){
        dp[v][i] = dp[dp[v][i-1]][i-1];
    }
    for (ll u : adj[v]) {
        if (u != p){
            dfs(u, v);
        }
    }
    time_out[v] = ++timer;
}

int main(){
	ll tc; cin >> tc;
	FOR1(blah, tc){
		cin >> n >> a >> b;
		adj.clear(), dp1.clear(), dp2.clear();
		adj.resize(n + 1), dp1.assign(n + 1, 1), dp2.assign(n + 1, 1);
		for (ll i = 2; i <= n; ++i){
			cin >> x;
			adj[x].pb(i);
			adj[i].pb(x);
		}
		dfs(1, 0);
		solve(1, 0);
		ans = 0.0;
		FOR1(i, n) ans += dp1[i] * n + dp2[i] * n - dp1[i] * dp2[i];
		ans /= (n*n);
		cout << "Case #" << blah << ": " << fixed << setprecision(8) << ans << endl;
	}
}