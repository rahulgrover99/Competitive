#include <bits/stdc++.h>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define FORl(i, l, n) for (int i = l; i < n; i++)
using namespace std;
#define pi pair<ll, ll>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define mst0(x) memset(x, 0, sizeof(x));
#define vi vector<ll>
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define sp << " " <<
#define intmax 1e14
ll mod = 1e9 + 7;

ll power(ll num, ll g, ll mod)
{
    if (g == 0)
        return 1;
    if (g % 2 == 1)
        return (num * power((num * num) % mod, g / 2, mod)) % mod;
    return power((num * num) % mod, g / 2, mod);
}

pi a[800001];
map<ll, ll> dp;

int main(){
    freopen("timber_input.txt","r",stdin);
	freopen("timber_output.txt","w",stdout);
	int tc;
    cin >> tc;
    FOR1(blah, tc){
        mst0(a);
        dp.clear();
		cout << "Case #" << blah << ": ";
        int n;
		cin >> n;
		FOR0(i, n) cin >> a[i].ff >> a[i].ss;
		sort(a, a + n);
		for(int i = 0; i < n; i++){
			if(i == 0){
				dp[a[i].ff] = a[i].ss;
				dp[a[i].ff + a[i].ss] = a[i].ss;
				continue;
			}
			dp[a[i].ff + a[i].ss] = max(dp[a[i].ff + a[i].ss] ,a[i].ss + dp[a[i].ff]);
			dp[a[i].ff] = max(dp[a[i].ff], a[i].ss + dp[a[i].ff - a[i].ss]);
		}
		ll ans = 0;
		for(auto val: dp) ans = max(ans, val.ss);
		cout << ans << endl;
    }
}