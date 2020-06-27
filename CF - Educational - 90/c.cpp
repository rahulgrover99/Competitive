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


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt = 0;
        int n = s.size();
        int arr[n];
        FOR0(i, n) 
            if (s[i] == '+') arr[i] = ++cnt;
            else arr[i] = --cnt;
        int tmp = -1;
        // stack<int> st;
        ll ans = n;
        FOR0(i, n){
            if (arr[i] == tmp){
                tmp--;
                ans += (i + 1);
            }
        }
        cout << ans << endl;
    }
}