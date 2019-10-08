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
ll mod = 1e9 + 7;
const int sz = 2e5 + 5;
ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}


bool cmp (pi a, pi b){
	if (a.ss!=b.ss)return a.ss < b.ss;
	return a.ff < b.ff;
}
int main(){
    int n;
    cin >> n;
    pi x[n];

    ll ans = 0;
    FOR0(i,n){
    	cin >> x[i].ff >> x[i].ss;
    }
    sort(x,x+n);
    ll c = 1;
    ll t = 1;
    FOR0(i,n-1){
    	if (x[i].ff==x[i+1].ff) {
    		c++;
    		
    	}
    	else{
    		ans += c*(c-1)/2;
    		c = 1;
    	}
    	if (x[i].ss==x[i+1].ss && x[i].ff==x[i+1].ff) t++;
    	else {
			ans -= t*(t-1)/2;
			t = 1;
		}
    }
    ans += c*(c-1)/2;
    ans -= t*(t-1)/2;
    sort(x,x+n, cmp);
    c = 1;
    FOR0(i,n-1){
    	if (x[i].ss==x[i+1].ss) c++;
    	else{
    		ans += c*(c-1)/2;
    		c = 1;
    	}
    }
    ans += c*(c-1)/2;
    cout << ans;
}

/*
MUCH EASILY IMPLEMENTED SOLUTION
#include <iostream>
#include <map>
using namespace std;
long long n,ans,x,y;
map<int,int> nx, ny;
map<pair<int,int>,int> np;
int main(){
	cin>>n;
	while(n--){
		cin>>x>>y;
		ans+= (nx[x]++) + (ny[y]++) - (np[make_pair(x,y)]++);
	}
	cout<<ans<<endl;
}
*/