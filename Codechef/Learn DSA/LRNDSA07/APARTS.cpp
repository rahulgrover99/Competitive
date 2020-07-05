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
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        FOR0(i, n) {
            FOR0(j, m) {
                cin >> a[i][j];
            }
        }
        FOR0(i, n) {
            FOR0(j, m) {
                int cur = a[i][j];
                if (i > 0 and j > 0) a[i][j] = max(a[i - 1][j - 1], a[i][j]);
                if (i > 0) a[i][j] = max(a[i - 1][j], a[i][j]);
                if (i > 0 and j < m - 1) a[i][j] = max(a[i - 1][j + 1], a[i][j]);
                cout << (cur >= a[i][j]);
            }
            cout << endl;
        }
    }
}