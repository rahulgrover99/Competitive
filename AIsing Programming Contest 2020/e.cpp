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
    while(t--){
        ll n;
        cin >> n;
        pi arr[n];
        ll l[n], r[n], k[n];
        FOR0(i, n){
            cin >> k[i] >> l[i] >> r[i];
            k[i]--;
            arr[i].ff = abs(l[i] - r[i]);
            arr[i].ss = i;
        }
        sort(arr, arr + n, greater<pi>());
        set<int> left, right;
        FOR0(i, n){
            left.insert(i);
            right.insert(i);
        }
        ll ans = 0;
        FOR0(i, n){
            ll k1 = k[arr[i].ss];
            ll l1 = l[arr[i].ss];
            ll r1 = r[arr[i].ss];
            if (l1 > r1){
                auto itr = left.upper_bound(k1);
                if (itr!= left.begin()){
                    ans += l1;
					itr--;
				    left.erase(itr);
					right.erase(right.begin());     
                }
                else ans += r1;
            } 
            else{
                auto itr = right.upper_bound(k1);
                if (itr!= right.end()){
                    ans += r1;
				    right.erase(itr);
					left.erase(--left.end());     
                }
                else ans += l1;
            }
        }
        cout << ans << endl;

    }
}