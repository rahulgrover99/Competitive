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
		ll n;
		cin >> n;
	    ll t1 = 0, t2 = 0;
	    string s;
	    cin >> s;
	    string ans="";
	    FOR0(i,n){
	        if(s[i]!='0'){
	            break;
	        }
	            
	        t1++;
	        cout<<"0";
	    }
	    for(ll i =n-1 ; i>=0 ; i--){
	        if(s[i]!='1'){
	            break;
	        }
	        t2++;     
	        ans+= s[i];
	    }
	    if(t1+ t2 != n){
	        cout<< "0" ;
	    }
	        
	    cout << ans <<endl;


    }
}