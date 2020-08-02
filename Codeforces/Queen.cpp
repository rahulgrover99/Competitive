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
#define vi vector<int>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define sp <<" "<<
#define intmax 1e14
 
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}
 
int main(){
    int n;
    cin >> n;
    vi v[n+1];
    int a[n + 1];
    int x, t;
    FOR1(i, n){
        cin >> x >> a[i];
        if (x == -1) continue;
        v[x].pb(i);
    }
    bool chk = false, flag = true;
    FOR1(i, n){
        flag = true;
        if (a[i]){
            for (auto tmp: v[i]){
                if (a[tmp] == 0){
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << i << " ";
                chk = true;
            }
        }
        
    }
    if (!chk) cout << -1;
}