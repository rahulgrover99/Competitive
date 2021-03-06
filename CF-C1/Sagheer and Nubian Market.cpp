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
const int sz = 2e5 + 5;
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

int n, S;
int a[sz];
ll b[sz];
 
ll tot(int k){
    FOR0(i,n) b[i] = a[i] + (i + 1) * (ll) k;
    sort(b, b + n);
    ll ans = 0;
    FOR0(i,k) ans += b[i];
    return ans;
}

int main(){
	cin >> n >> S;
	FOR0(i,n) cin >> a[i];
    int l = 0, r = n;
    while (l < r){
        int m = (l + r + 1) / 2;
        if (tot(m) <= S)
            l = m;
        else
            r = m - 1;
    }
    cout << l sp tot(l) << endl;
}