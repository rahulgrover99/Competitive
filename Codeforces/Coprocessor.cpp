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
#define vi vector<int>
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define sp <<" "<<
#define intmax 1e14
 
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}
 
vi v[100001];
int indegree[100001], arr[100001];
int main(){
    mst0(indegree);
    int n, m, x, y;
    cin >> n >> m;
    FOR0(i, n) cin >> arr[i];
    FOR0(i, m){
        cin >> x >> y;
        v[y].pb(x);
        indegree[x]++;
    }
    queue<int> q[2];
    FOR0(i, n){
        if (indegree[i] == 0){
            q[arr[i]].push(i);
        }
    }
    int ans = 0, cnt = 0;
    while(cnt < n){
        while(!q[0].empty()){
            x = q[0].front();
            // cout << x << endl;
            q[0].pop();
            cnt++;
            for (auto u: v[x]){
                indegree[u]--;
                if (indegree[u]==0){
                    q[arr[u]].push(u);
                }
            }
        }
        int chk = 0;
        while(!q[1].empty()){
            chk = 1;
            x = q[1].front();
            q[1].pop();
            cnt++;
            for (auto u: v[x]){
                indegree[u]--;
                if (indegree[u]==0){
                    q[arr[u]].push(u);
                }
            }
        }
        ans += chk;
    }
    cout << ans << endl;
}