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
    int h, w, k;
    cin >> h >> w >> k;
    string matrix[h];
    int ans = 0;
    FOR0(i, h) cin >> matrix[i];
    for (int i = 0; i < (1<<(h+w)); i++){
        string tmp[h];
        FOR0(t, h) tmp[t] = matrix[t];

        for (int d = 0; d < h; d++){
            if (i&(1<<d)){
                for (int j = 0; j < w; j++) tmp[d][j] = 'R';
            }
        }

        for (int d = 0; d < w; d++){
            if (i&(1<<(d+h))){
                for (int j = 0; j < h; j++) tmp[j][d] = 'R';
            }
        }

        int cnt = 0;
        FOR0(rows, h) FOR0(cols, w) if (tmp[rows][cols] == '#') cnt++;
        if (cnt == k) ans++;
    }
    cout << ans << endl;
}