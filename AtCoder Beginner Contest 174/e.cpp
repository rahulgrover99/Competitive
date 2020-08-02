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

ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}

ll n, k;
ll a[200001];

bool chk(ll len){
    int cnt = 0;
    FOR0(i, n){
        if (a[i] <= len) continue;
        else {
            cnt += ceil((ld)a[i]/(ld)len);
            cnt--;
            // if (len == 3){
            //     cout << ceil(a[i]/len) sp a[i]/len << endl;
            //     cout << cnt << endl;
            // }
        }
    }
    // cout << len sp cnt << endl;
    return cnt <= k;
}


int main(){
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    ll lo = 1, hi = 1e9 + 1;
    ll ans = 1e9;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if (chk(mid)){
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans << endl;

}