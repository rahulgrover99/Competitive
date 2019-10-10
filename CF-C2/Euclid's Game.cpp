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
	// 2 3 1 1 1 2
	while(1){
		int n, m;
		cin >> n >> m;
		if (n==0 && m==0) break;
		if (n<m) swap(n,m);
		int cnt = 1;
		while(1){
			if (n % m == 0 || n / m > 1){
				if (cnt) cout << "Stan wins" << endl;
				else cout << "Ollie wins" << endl;
				break;
			}
			n %= m;
			swap(n, m);
			cnt^=1;
		}
	}
}
/*
25 7
3 moves 
4 7 
1 move 
4 3
1 move 
1 3
3 moves 
1 0


15 24 
1 move
15 9
1 move
6 9 
1 move 
6 3
2 move

34 12
2 moves
10 12
1 move 
10 2
5 move
*/

