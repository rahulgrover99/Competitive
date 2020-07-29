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
    ll n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector<vi> mat(n + 1, vi(n + 1, 1e18));
    FOR0(i, m){
        cin >> a >> b >> c;
        mat[a][b] = mat[b][a] = min(mat[a][b], c);
    }
    // FOR1(i, n) mat[i][i] = 0;
    FOR1(k, n){
        FOR1(i, n){
            FOR1(j, n){
                if (mat[i][k] + mat[k][j] < mat[i][j]){
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if (a == b) mat[a][b] = 0;
        if (mat[a][b] == 1e18) mat[a][b] = -1;
        cout << mat[a][b] << endl;
    }
}