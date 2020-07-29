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

int main(){
    int n,k,m;
    cin >> n >> k >> m;
    map<string, int> mp;
    FOR1(i, n) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    ll arr[n], cost[n];
    FOR1(i, n){
        cin >> arr[i];
        cost[i] = LONG_LONG_MAX;
    }
    int group[n];
    FOR1(i, k){
        int x;
        cin >> x;
        while (x--){
            int a;
            cin >> a;
            group[a]=i;
            cost[i]=min(cost[i],arr[a]);
        }
    }
    ll ans=0;
    while (m--){
        string s;
        cin >> s;
        ans+=cost[group[mp[s]]];
    }
    cout << ans << endl;
}