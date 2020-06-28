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
    // sync
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        int a[n];
        unordered_map<int, int> freq;
        // mst0(freq);
        FOR0(i, n) {
            scanf("%d", &a[i]);
             a[i]%=k;
        }
        FOR0(i, n) freq[a[i]]++;
        freq[0] = 0;
        ll maxval = -1, ind = LONG_LONG_MAX;
        for (auto x : freq){
            if (x.ss > maxval || (x.ss == maxval && x.ff < ind) ){
                maxval = x.ss;
                ind = x.ff;
            }
        }
        if (maxval == 0){
            cout << 0 << endl;
            continue;
        }
        // cout << maxval sp ind << endl;
        // maxval 0
        ll ans = 0;
        ans += (maxval - 1)*k;
        ans += k-ind;
        ans++;
        printf("%lld\n", ans);
    }
}