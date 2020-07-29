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

int x[4] = {0, 0, -1, 1};
int y[4] = {1, -1, 0, 0};



int dist[1001][1001];
int dist2[1001][1001];
pi parent[1001][1001];

bool chk = false;

string find_path(int i, int j){
    string ans = "";
    while(parent[i][j] != mp(-1LL, -1LL)){

        auto tmp = parent[i][j];

        if (tmp.ff == i && tmp.ss == j + 1) ans+="L";
        else if (tmp.ff == i && tmp.ss == j - 1) ans += "R";
        else if (tmp.ff == i + 1) ans += "U";
        else ans += "D";

        i = tmp.ff;
        j = tmp.ss;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    int n, m;
    cin >> n >> m;
    string s[n];
    FOR0(i, n) cin >> s[i];
    queue<pi> qu;
    FOR0(i, 1001) FOR0(j, 1001) dist[i][j] = INT_MAX, dist2[i][j] = INT_MAX;
    FOR0(i, n) FOR0(j, m) if (s[i][j] == 'M') qu.push({i, j}), dist[i][j] = 0;
    while(!qu.empty()){
        auto tmp = qu.front();
        qu.pop();
        int i = tmp.ff;
        int j = tmp.ss;
        for (int k = 0; k < 4; k++){
            int x_new = i + x[k];
            int y_new = j + y[k];
            if (x_new < n && x_new >= 0 && y_new < m && y_new >= 0 && dist[x_new][y_new] == INT_MAX && s[x_new][y_new] != '#') {
                qu.push({x_new, y_new});
                dist[x_new][y_new] = dist[i][j] + 1;
            }
        }
    }
    // FOR0(i, n) {
    // FOR0(j, m) {
    //     cout << dist[i][j] << " ";
    // }
    // cout << endl;
    // }
    memset(parent, -1, sizeof(parent));
    FOR0(i, n) {
        FOR0(j, m){
            if (s[i][j] == 'A') {
                qu.push({i, j}), dist2[i][j] = 0;
                if (i == n-1 || j == m-1 || i == 0 || j == 0){
                    chk = true;
                    cout << "YES" << endl << dist2[i][j] << endl << find_path(i, j);
                    return 0;
                }
            }
        }
    }
    while(!qu.empty() && !chk){
        auto tmp = qu.front();
        qu.pop();
        int i = tmp.ff;
        int j = tmp.ss;
        // cout << i << " " << j << endl;
        for (int k = 0; k < 4; k++){
            int x_new = i + x[k];
            int y_new = j + y[k];
    
            if (x_new < n && x_new >= 0 && y_new < m && y_new >= 0 && dist2[x_new][y_new] == INT_MAX && s[x_new][y_new] != '#' && dist[x_new][y_new] > dist2[i][j] + 1) {
                
                qu.push({x_new, y_new});
                parent[x_new][y_new] = {i, j};
                dist2[x_new][y_new] = dist2[i][j] + 1;

                if (x_new == n-1 || y_new == m-1 || x_new == 0 || y_new == 0){
                    chk = true;
                    cout << "YES" << endl << dist2[x_new][y_new] << endl << find_path(x_new, y_new);
                    return 0;
                }
                
            }
        }
    } 
    // FOR0(i, n) {
    // FOR0(j, m) {
    //     cout << dist2[i][j] << " ";
    // }
    // cout << endl;
    // }
    cout << "NO" << endl;

}