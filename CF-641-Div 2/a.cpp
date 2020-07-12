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

ll power(ll num,ll g,ll mod){
  if(g==0)return 1;
  if(g%2==1)return (num*power((num*num)%mod,g/2,mod))%mod;
  return power((num*num)%mod,g/2,mod);
}


class GridSpiral
{
public:
	long long findcell(int D){
		if(D%2 == 0){
			return -1;
		}
		if(D <= 7){
			return 0;
		}
		if(D == 9){
			return 1;
		}
		if((D-11)%2 != 0){
			return 0;
		}
		ll n = (D - 11)/2;
		n++;
		if(n == 1){
			return 2;
		}
		if(n == 2){
			return 4;
		}
		if(n%2 == 1){
			ll val = n/2;
			ll sum = ((val+1)*(val+2))/2;
			sum -= 1;
			sum *= 2;
			sum += 2;
			return sum;
		}else{
			ll val = n/2;
			ll sum = (val*(val+1))/2;
			sum -= 1;
			sum *= 2;
			sum += 2;
			sum += (val+1);
			return sum;
		}
	}
	
};

int main()
{
	sync;
	ll t;
	cin >> t;
	while(t--)
	{
		int d;
		cin >> d;
		GridSpiral solver;
		cout << solver.findcell(d)<< endl;
	}	
	return 0;
}