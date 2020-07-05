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
ll mod = 1e9 + 7;

ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

ll dp[8001][1008];

int main() {
    int n, k;
    cin >> n >> k;
    k = min(k, 1007);
    int a[n];
    FOR0(i, n) cin >> a[i];
    map<int, int> mp;
    FOR0(i, n) mp[a[i]]++;
    mst0(dp);
    int i = 0;
    for (int p = 0; p < 8001; p++) dp[p][0] = 1;
    for (auto x : mp){
        if (i == 0) {
            dp[0][1] = x.ss;
            i++;
            continue;
        }
        for (int j = 1; j <= k; j++){
            dp[i][j] += dp[i - 1][j];
            dp[i][j] = dp[i][j] % mod;
            dp[i][j] += (dp[i - 1][j - 1]) * x.ss;
            dp[i][j] = dp[i][j] % mod;
        }

        i++;
    }
    ll ans = 0;
    FOR0(p, k + 1) ans = (ans + dp[i-1][p])%mod;
    cout << ans << endl;
}