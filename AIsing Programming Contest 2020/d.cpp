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
const int M = 200005;
ll dp1[M], dp2[M];
ll ans[M];

int main()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll X = 0, N = 0;
	FOR0(i,n){
		if(s[i] == '1'){
			N++;
		}
	}
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	memset(ans, -1, sizeof(ans));
	dp2[n-1] = 1;
	if((N-1) >= 1){
		dp1[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			dp1[i] = (2*dp1[i+1])%(N-1);
		}
	}
	for(int i = n-2; i >= 0; i--){
		dp2[i] = (2*dp2[i+1])%(N+1);
	}
	ll sum1 = 0, sum2 = 0;
	for(int i = n-1; i >= 0; i--){
		if((N-1) >= 1){
			if(s[i] == '1'){
				sum1 += dp1[i];
				sum1 %= (N-1);
			}
		}
		if(s[i] == '1'){
			sum2 += dp2[i];
			sum2 %= (N+1);
		}
	}
	FOR0(i,n){
		if(s[i] == '1'){
			X += (1LL<<(n-1-i));
		}
	}
	vector<ll> v;
	for(int i = 0; i < n; i++){
		ll val;
		if(s[i] == '0'){
			val = (sum2 + dp2[i])%(N+1);
		}else{
			val = 0;
			if(N == 1){
				ans[i] = 0;
			}
			if((N-1) >= 1){
				val = (sum1 - dp1[i] + N - 1)%(N-1);
			}
		}
		v.push_back(val);
	}
	for(int i = 0; i < n; i++){
		if(ans[i] == -1){
			ans[i] = 1;
		}
		ll val = v[i];
		ll cnt = 0;
		while(val > 0){
			val %= (__builtin_popcount(val));
			cnt++;
		}
		ans[i] += cnt;
	}
	FOR0(i,n){
		cout << ans[i] << endl;
	}
}