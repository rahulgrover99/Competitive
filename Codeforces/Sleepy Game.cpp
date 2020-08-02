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

vi graph[100001];

bool cycle = false;
int s;
int visited[100001];
int parent[100001][2];

void dfs_cycle(int n){
    visited[n] = 1;
    for(auto v: graph[n]){
        // cout << n sp v sp visited[v] << endl;
        if (visited[v] == 0){
            dfs_cycle(v);
        }
        else if (visited[v]==1){
            // cout << n << endl;
            cycle = true;
        }
    }
    visited[n] = 2;
}

// void dfs(int n, int parity){
//     // cout << n << endl;
//     visited[n] = 1;
//     int cnt = 0;
//     for(auto v: graph[n]){
//         // cout << v << endl;
//         cnt++;
//         if (visited[v] == 0){
//             parent[v][0] = n;
//             dfs(v, parity^1);

//         }
//         else if (visited[n]==1){
//             cycle = true;
//         }
//     }
//     visited[n] = 2;
//     // Leaf node
//     if (cnt == 0){
//         // cout << n sp parity << endl;
//         if (parity == 1) win = true;
//         if (win && path.empty()){
//             while(parent[n] != -1){
//                 path.pb(n);
//                 n = parent[n];
//             }
//             path.push_back(n);
//         }
//     }
// }
const int maxn = 1e5+5;
vector<int> win(maxn);
vector<int> los(maxn);

// void dfs(int s,int p,int par){
//     if (p==0) parent[s][0]=par;
//     else parent[s][1]=par;
//     //cout<<++cnt;
//     for (auto cur: graph[s]){
//         int pp = p^1;
//         if (pp==0 && parent[cur][1]==0)
//             dfs(cur,pp,s);
//         else if (pp==1 && parent[cur][1]==0)
//             dfs(cur,pp,s);
//     }
// }
void dfs(int s,int p,int par){
    if (p==0)los[s]=par;
    else win[s]=par;
    for (int i=0;i<graph[s].size();i++)
    {   int cur = graph[s][i];
        int pp = p^1;
        if (pp==0 && los[cur]==0)
            dfs(cur,pp,s);
        else if (pp==1 && win[cur]==0)
            dfs(cur,pp,s);
    }
}
// void dfs(int n, int parity){
//     int cnt = 0;
//     // cout << n sp parity << endl;
//     for (auto v: graph[n]){
//         cnt++;
//         if (1 - parity == 0 && parent[v][0] == 0){
//             parent[v][0] = n;
//             dfs(v, parity^1);
//         }
//         else if (1 - parity == 1 && parent[v][1] == 0){
//             parent[v][1] = n;
//             dfs(v, parity^1);
//         }
//     }
//     if (cnt == 0 && parent[n][1] != 0 && path.empty()){
//         win = true;
        
//     }
// }

int main() {
    mst0(visited);
    mst0(parent);
    int n, m, x, v;
    cin >> n >> m;
    FOR1(i, n){
        cin >> x;
        FOR0(j, x){
            cin >> v;
            graph[i].pb(v);
        }
    }
    cin >> s;
    // parent[s] = -1;
    
    dfs_cycle(s);
    
    dfs(s, 0, s);
        
    FOR1(i, n){
        if (win[i]!=0 && graph[i].size()==0){
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
            reverse(path.begin(), path.end());
            for (auto node: path) cout << node << " ";
            cout << endl;
            return 0;
        }
    }
        
    if (cycle){
        cout << "Draw" << endl;
    }
    else {
        cout << "Lose" << endl;
    }

}
