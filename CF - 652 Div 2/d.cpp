#include <bits/stdc++.h>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define FORl(i, l, n) for (int i = l; i < n; i++)
using namespace std;
#define pi pair<ll, ll>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define mst0(x) memset(x, 0, sizeof(x));
#define vi vector<ll>
#define sync                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define endl '\n'
#define sp << " " <<
#define intmax 1e14
ll mod = 1e9 + 7;

ll dp[2000001], center[2000001];

int main(){
    dp[1] = dp[2] = 0;
    dp[3] = 4;
    dp[4] = 4;
    mst0(center);
    center[3] = 1;

    for(int i = 5; i < 2000001; i++){
        if(center[i-1] == 0 && center[i-2] == 0){
            dp[i] = (dp[i-1] + dp[i-2]*2 + 4)%mod;
            center[i] = 1;
        }
        else{
            dp[i] =  (dp[i-1] + dp[i-2]*2) %mod;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}