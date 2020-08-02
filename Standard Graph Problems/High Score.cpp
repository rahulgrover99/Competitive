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

struct edge
{
    ll a, b, cost;
};
edge v[5001];
vi graph[2501];
vector<ll> d(2501, -1e14);
bool vis[2501];
bool chk = false;
set<int> nodes;
void dfs(int a){
    if (nodes.find(a)!=nodes.end()) chk = true;
    vis[a] = 1;
    for (auto x: graph[a]){
        if (!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    // freopen("test_input.txt","r",stdin);
	// freopen("test_output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    // ll a, b, c;
    mst0(vis);
    FOR0(i, m){
        cin >> v[i].a >> v[i].b >> v[i].cost;
        graph[v[i].b].pb(v[i].a);
    }   
    
    d[1] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[v[j].a] != -1e14 && d[v[j].a] + v[j].cost > d[v[j].b])
                d[v[j].b] = max(d[v[j].b], d[v[j].a] + v[j].cost);

    
    for (int j=0; j<m; ++j)
        if (d[v[j].a] != -1e14 && d[v[j].a] + v[j].cost > d[v[j].b]){
            d[v[j].b] = max(d[v[j].b], d[v[j].a] + v[j].cost);
            nodes.insert(v[j].b);
        }

    dfs(n);

    if (chk) cout << -1 << endl;
    else cout << d[n] << endl;
}


/*

#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define f(a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn = 1e5+5;
vector<int> vec[maxn];
vector<int> color(maxn);
vector<int> win(maxn);
vector<int> los(maxn);
bool cycle=false;
void dfs(int s){
    color[s]=1;
    for (int i=0;i<vec[s].size();i++)
    {
        if (color[vec[s][i]]==0)
            dfs(vec[s][i]);
        else if (color[vec[s][i]]==1)
        {
            cycle=true;
        }
    }
    color[s]=2;
}
int cnt=0;
void dfs(int s,int p,int par){
    if (p==0)los[s]=par;
    else win[s]=par;
    //cout<<++cnt;
    for (int i=0;i<vec[s].size();i++)
    {   int cur = vec[s][i];
        int pp = p^1;
        if (pp==0 && los[cur]==0)
            dfs(cur,pp,s);
        else if (pp==1 && win[cur]==0)
            dfs(cur,pp,s);
    }
}
 
int main()
{
    int n,m;
    cin>>n>>m;
 
    for (int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        int x;
        for (int j=0;j<c;j++)
           {
               cin>>x;
               vec[i].push_back(x);
           }
    }
 
    int s;
    cin>>s;
    dfs(s);
 
    dfs(s,0,s);
    for (int i=1;i<=n;i++)
    {
        if (win[i]!=0 && vec[i].size()==0)
        {
            cout<<"Win\n";
            vector<int> path;
            path.push_back(i);
            int cur=i;
            int par=win[i];
            int ctr=0;
            while(1)
            {
                ctr=ctr^1;
                if (ctr==0){
                    cur=los[cur];
                }
                else{
                    cur=win[cur];
                }
                path.push_back(cur);
                if (cur==win[cur] && ctr==0)break;
                if (cur==los[cur] && ctr==1)break;
 
            }
            assert(path.size()<=1000000);
            for (int i=path.size()-1;i>=0;i--){
                cout<<path[i]<<" ";
            }
            return 0;
        }
    }
    if (cycle)cout<<"Draw";
    else
    cout<<"Lose";
 
}
*/