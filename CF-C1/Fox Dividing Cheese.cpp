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

int a,b,res;
void check(int x){
	int z=0,y=0;
	while(a%x==0){ 
		a/=x; 
		z++; 
	}
	while(b%x==0){ 
		b/=x; 
		y++; 
	}
	res+=abs(z-y);
}
int main(){
	cin>>a>>b;
	check(2),check(3),check(5);
	if(a!=b) cout<<-1;
	else cout<<res;
}