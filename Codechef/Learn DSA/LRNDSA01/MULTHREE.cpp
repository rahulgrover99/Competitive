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

int main() {
    int t;
    cin >> t;
    while(t--){
        ll k, d0, d1;
        cin >> k >> d0 >> d1;
        ll sum = d0+d1;
        ll ans = sum;
	    ll tsum = (2*sum) % 10 + (4*sum) % 10 + (8*sum) % 10 + (6*sum) % 10;
	    k -= 2;
        if(k > 0) {
            ans += (sum % 10);
            k--;
        }
        ans += (k / 4) * tsum;
        k %= 4;
        int p = 2;
        while(k--) {
            ans += (p*sum) % 10;
            p = (p * 2) % 10;
        }
        if((ans % 3) == 0) cout<<"YES\n";
        else cout<<"NO\n";	
    }
}