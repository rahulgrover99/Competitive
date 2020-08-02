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
    int n;
	cin >> n;
	string s;
	cin >> s;
	vi v;
	FOR0(i,n){
		if(s[i] == 'R')	v.pb(i);
	}
	int m = v.size();
	if(m == n || m == 0){
		cout << "0" << endl;
		return 0;
	}
	int j = m-1, cnt = 0;
	FOR0(i,n){
		if(s[i] == 'W' && v[j] > i){
			cnt++;
			j--;
		}
		if(j < 0) break;
	}
	cout << cnt << endl;
}