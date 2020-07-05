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
    int cnt[100001];
    mst0(cnt);
    int cum[100001][10];
    mst0(cum);
    for (int i = 2; i < 100001; i++){
        if (cnt[i]==0){
            for (int j = i; j < 100001; j+=i){
                cnt[j]++;
            }
        }
    }
    for (int i = 2; i < 100001; i++) if (cnt[i] == 0) cnt[i] = 1;
    for (int i = 2; i < 100001; i++) if (cnt[i] < 10) cum[i][cnt[i]] = 1;
    for (int i = 3; i < 100001; i++){
        for (int j = 1; j < 10; j++){
            cum[i][j] += cum[i-1][j];
        }
    }
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        cout << cum[b][k] - cum[a-1][k] << endl;
    }
}