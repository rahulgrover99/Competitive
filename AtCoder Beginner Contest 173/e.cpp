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
    int n, k;
    cin >> n >> k;
    ll a[n];
    FOR0(i, n) cin >> a[i];
    sort(a, a+n);
    ll ans = 1;
    if (a[n-1]==0 && k%2==1){
        cout << 0 << endl;
        return 0;
    }
    if (a[n-1] < 0 && k%2==1){
        for (int i = n - 1; i >= n - k; i--) ans = (ans*a[i] + mod)%mod;
        cout << ans << endl;
        return 0;
    }
    int i = 0, j = n-1;
    if (k %2 == 1) { 
        ans *= a[j];
        ans += mod;
        ans %= mod; 
        j--; 
        k--; 
    } 
    k/=2;
    for (int itr = 0; itr < k; itr++) { 
  
        ll left_product = a[i] * a[i + 1]; 
        ll right_product = a[j] * a[j - 1]; 
 
        if (left_product > right_product) { 
            left_product += mod;
            left_product%=mod;
            ans *= left_product; 
            i += 2; 
            ans += mod;
            ans %= mod;
        } 
        else { 
            right_product += mod;
            right_product%=mod;
            ans *= right_product; 
            j -= 2; 
            ans += mod;
            ans %= mod;
        } 
    } 
    cout << ans << endl;
 
}