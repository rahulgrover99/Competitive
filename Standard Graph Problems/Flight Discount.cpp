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

ll dist[100001][3];
vector<pi> graph[100001];
int main(){
    // freopen("test_input.txt","r",stdin);
	// freopen("test_output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    ll a, b, c;
    // mst0(vis);
    FOR0(i, m){
        cin >> a >> b >> c;
        graph[a].pb({b, c});
    }
    FOR0(i, 100001) dist[i][0] = dist[i][1] = dist[i][2] = 1e15;
    dist[1][0] = dist[1][1] = dist[1][2] = 0;
    set<pair<ll, pi> > q;
    q.insert({0, {0, 1}});
    q.insert({0, {1, 1}});
    q.insert({0, {2, 1}});
    while(!q.empty()){
        auto tmp = *q.begin();
        q.erase(q.begin());
        ll wt = tmp.ff;
        int type = tmp.ss.ff;
        int u = tmp.ss.ss;
        for (auto edge: graph[u]){
            ll len = edge.ss;
            ll v = edge.ff;
            if (type == 0){
                if (wt + len < dist[v][0]){
                    q.erase({dist[v][0], {0, v}});
                    dist[v][0] = wt + len;
                    q.insert({dist[v][0], {0, v}});
                }
                if (wt + len/2 < dist[v][1]){
                    q.erase({dist[v][1], {1, v}});
                    dist[v][1] = wt + len/2;
                    q.insert({dist[v][1], {1, v}});
                }
            }
            else{
                if (wt + len < dist[v][2]){
                    q.erase({dist[v][2], {2, v}});
                    dist[v][2] = wt + len;
                    q.insert({dist[v][2], {2, v}});
                }
            }
        }
    }
    cout << min(dist[n][0], min(dist[n][1], dist[n][2]));

}