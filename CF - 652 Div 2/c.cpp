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


int main(){
    ll t;
	cin >> t;
	while(t--)
	{
		ll n, k;
		cin >> n >> k;
		ll a[n+5], b[k+5];
		FOR0(i,n){
			cin >> a[i];
		}
		FOR0(i,k){
			cin >> b[i];
		}
		sort(b,b+k);
		sort(a,a+n);
		ll sum = 0, temp = n-1;
		FOR0(i,k){
			sum += a[temp];
			temp--;
		}
		ll curr = 0, idx = -1;
		for(int i = k-1; i >= 0; i--){
			ll tmp = b[i] - 1;
			if(tmp == 0){
				idx = i;
				break;
			}else{
				sum += a[curr];
				curr += tmp;
			}
		}
		ll lol = n-1;
		for(int i = 0; i <= idx; i++){
			sum += a[lol];
			lol--;
		}
		cout << sum << endl;
	}
}