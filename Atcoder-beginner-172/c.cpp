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

ll n, m ,k;
const int  N = 200005;
ll a[N], b[N], dp[N], pp[N];
int main() {
    cin >> n >> m >> k;
	FOR0(i,n){
		cin >> a[i];
		if(i == 0){
			dp[i] = a[i];
			continue;
		}
		dp[i] = dp[i-1] + a[i];
	}
	FOR0(i,m){
		cin >> b[i];
		if(i == 0){
			pp[i] = b[i];
			continue;
		}
		pp[i] = pp[i-1] + b[i];
	}
	ll p1 = 0, p2 = 0;
	FOR0(i,n){
		if(dp[i] <= k){
			p1 = i + 1;
		}
	}
	FOR0(i,m){
		if(pp[i] <= k){
			p2 = i + 1;
		}
	}
	ll ans = 0;
	FOR0(i,n){
		ll val = k - dp[i]; 
		if(val < 0){
			break;
		}
		ll pos = lower_bound(pp,pp+m,val) - pp;
		if(pos == m){
			pos--;
		}
		else if(pp[pos] != val){
			pos--;
			if(pos < 0){
				continue;
			}
		}
		ans = max(ans, pos + i + 2);
	}
	ans = max(ans, max(p1,p2));
	cout << ans << endl;
}