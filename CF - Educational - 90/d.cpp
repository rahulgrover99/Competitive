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
    int t;
    cin >> t;
    while(t--){
        ll n;
		cin >> n;
		ll a[n+5];
		ll sum = 0;
		FOR0(i,n){
			cin >> a[i];
			if(i%2 == 0){
				sum += a[i];
			}
		}
		ll even = 0, odd = 0, ans = 0, curr = 0;
		FOR0(i,n){
			if(i%2 == 0){
				even += a[i];
				continue;
			}else{
				odd += a[i];
			}
			curr = (odd - even);
			if(curr < 0){
				curr = 0;
				even = 0;
				odd = 0;
			}
			ans = max(ans, curr);
		}
		even = 0, curr = 0, odd =0;
		for(int i = 1; i < n; i++){
			if(i%2 == 0){
				even += a[i];
			}else{
				odd += a[i];
				continue;
			}
			curr = (odd - even);
			if(curr < 0){
				curr = 0;
				even = 0;
				odd = 0;
			}
			ans = max(ans, curr);
		}
		sum += ans;
		cout << sum << endl;

    }
}