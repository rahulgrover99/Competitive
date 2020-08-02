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
    int numCourses, m;
    cin >> numCourses >> m;


    int freq[numCourses+1];
    memset(freq, 0, sizeof(freq));

    int x, y;
    
    vector< vector<int> > adj(numCourses + 1);
    FOR0(i, m){
        cin >> x >> y;
        adj[x].pb(y);
        freq[y]++;
    }
    vector <int> ans;
    int visited[numCourses + 1];
    memset(visited, 0, sizeof(visited));
    queue <int> qu;
    for (int i = 1; i < numCourses + 1; i++){
        if (freq[i]==0) {
            qu.push(i);
            visited[i] = 1;
            ans.push_back(i);
        }
    }
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        for (int i = 0; i < adj[node].size(); i++){
            if (!visited[adj[node][i]]){
                //visited[adj[node][i]] = 1;
                freq[adj[node][i]]--;
                if (freq[adj[node][i]]==0) {
                    qu.push(adj[node][i]);
                    visited[adj[node][i]] = 1;
                    ans.push_back(adj[node][i]);
                }
            }
        }
    }
    for (int i = 1; i < numCourses + 1; i++){
        if (visited[i] == 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (auto x: ans) cout << x << " ";
    cout << endl;
}