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

#define MOD 1000000007

const int N = 500005;
ll fact[N], invfact[N];

ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll modinv(ll k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(ll i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(ll i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

ll nCr(ll x, ll y)
{
	if(y>x)
		return 0;
	ll num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}

ll dp[N], dp1[N];

int main(int argc, char const *argv[])
{
	sync;
	precompute();
	ll n, m;
	cin >> n >> m;
	if(m == 1 || n > m){
		cout << "0" << endl;
		return 0;
	}
	ll ans = 1, val = m;
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		ans *= val;
		ans %= mod;
		dp[i] = dp[i-1]*val;
		dp[i] %= mod;
		val--;
	}
	val = m - n + 1;
	dp1[n] = val;
	dp1[n+1] = 1;
	//cout << dp1[n] << endl;
	for(int i = n-1; i >= 1; i--){
		val++;
		dp1[i] = dp1[i+1]*val;
		dp1[i] %= mod;
	}

	ans *= ans;
	ans %= mod;
	ll sign = -1;
	val = m;
	//cout << n sp nCr(n,1) << endl;
	for(int i = 1; i <= n; i++){
		ll tmp = dp1[i+1]*dp1[i+1];
		tmp %= mod;
		tmp *= dp[i];
		tmp %= mod;
		//cout << tmp sp nCr(n,i) sp sign*nCr(n,i)*tmp << endl;
		ans += sign*nCr(n,i)*tmp;
		ans %= mod;
		ans += mod;
		ans %= mod;
		sign = -sign;
	}

	cout << ans << endl;

	return 0;
}