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

int main(){
    int t;
    cin >> t;
    ll dp[53][1379];
    mst0(dp);
    dp[0][0] = 1;
    // for (int i = 1; i <= 52; i++) dp[1][i] = 1;
    for (int i = 1; i <= 52; i++) {
		for (int j = 52; j >= 1; j--) {
			for (int k = 1378; k >=i; k--) {
				dp[j][k] += dp[j - 1][k - i];
			}
		}
	}
    FOR1(i, t){
        int l, s;
        cin >> l >> s;
        if (l > 52 || s > 1378) {
            cout << "Case " << i << ": " << 0 << endl;
            continue;
        }
        cout << "Case " << i << ": " << dp[l][s] << endl;


    }
}