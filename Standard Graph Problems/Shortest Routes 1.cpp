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
    int n, m;
    cin >> n >> m;
    vector<pi> v[n + 1];
    FOR0(i, m){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        v[a].pb({b, c});
    }
    ll dist[n + 1];
    FOR1(i, n) dist[i] = 1e16;
    dist[1] = 0;
    bool visited[n + 1];
    mst0(visited);
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if (visited[x.ss]) continue;
        visited[x.ss] = true;
        for (auto u: v[x.ss]){
            if (dist[u.ff] > dist[x.ss] + u.ss){
                dist[u.ff] = dist[x.ss] + u.ss;
                pq.push({dist[u.ff], u.ff});
            }
        }
    }
    FOR1(i, n) cout << dist[i] << " ";

}