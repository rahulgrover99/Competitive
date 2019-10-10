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
	int t;
   	cin>>t;
   	while(t--){
      	double u,v,w,U,V,W,vol,a,b=12;
      	cin>>u>>v>>w>>W>>V>>U;
      
        a=4*(pow(u,2)*pow(v,2)*pow(w,2)) 
           - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) 
           - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) 
           - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) 
           + (pow(v,2)+pow(w,2)-pow(U,2))*
              (pow(w,2)+pow(u,2)-pow(V,2))*
              (pow(u,2)+pow(v,2)-pow(W,2));
        vol = sqrt(a);
        vol /= b;
      
      	cout << fixed << setprecision(4) << vol<<"\n";
   	}  
}