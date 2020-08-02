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

const int N = (int)2e5 + 100;
vi g[N];
bool vis[N];

void dfs(int v) {
	vis[v] = 1;
	for (auto to : g[v]) {
		if (!vis[to]) {
			dfs(to);
		}
	}
}

int main() {
    int n;
    cin >> n;
    FOR0(i, n){
        string s;
        cin >> s;
        for (char c : s) {
            g[i].push_back(n + c - 'a');
	        g[n + c - 'a'].push_back(i);
		}
    }
    int res = 0;
	for (int i = n; i < n + 26; i++) {
		if (!g[i].empty() && !vis[i]) {
			dfs(i);
			res++;
		}
	}
	cout << res;
}