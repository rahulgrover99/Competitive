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

int parent[100001];
ll c[100001];

int find_parent(int n){
    while(parent[n]!=n){
        parent[n] = parent[parent[n]];
        n = parent[n];
    }
    return n;
}

void Union(int a, int b){
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    if (p1!=p2){
        parent[p1] = p2;
        c[p2] = min(c[p2], c[p1]);
    }
}


int main(){
    int n, m, x, y;
    cin >> n >> m;
    FOR1(i, n) cin >> c[i], parent[i] = i;
    FOR1(i, m){
        cin >> x >> y;
        Union(x, y);
    }
    set<int>st;
    FOR1(i, n) st.insert(find_parent(i));
    ll sum = 0;
    for (auto x : st){
        sum += c[x];
    }
    cout << sum << endl;

}