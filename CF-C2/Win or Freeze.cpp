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
	ll q,ans = 0;
	cin >> q;
	for (ll i = 2; i*i <=q; i++){
		if(ans==0 && q%i==0){
			ans=i;
			q=q/i;
		}
		if(q%i==0 && q>i){
			cout << 1 << endl << ans*i;
			return 0;
		}
	}
	if(ans==0) cout << 1 << endl << 0;
	else cout << 2;
}