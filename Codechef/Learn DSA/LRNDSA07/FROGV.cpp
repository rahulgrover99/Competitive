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

int parent[100001];

int find_parent(int x){
    while(parent[x]!=x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union1(int i, int j){
    int a = find_parent(i);
    int b = find_parent(j);
    parent[a] = b;
}

int main() {
    ll n, k, p;
    cin >> n >> k >> p;
    pi a[n];
    FOR0(i, 100001) parent[i] = i;
    FOR0(i, n) cin >> a[i].ff, a[i].ss = i;
    sort(a, a + n);
    FOR0(i, n - 1){
        if (a[i + 1].ff - a[i].ff <= k) union1(a[i].ss, a[i + 1].ss);
    }
    while(p--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (find_parent(x) == find_parent(y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}