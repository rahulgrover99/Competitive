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

struct compare{
    bool operator()(const pi &lhs,const pi &rhs )const{
        if(lhs.ss-lhs.ff!=rhs.ss-rhs.ff) return lhs.ss-lhs.ff<rhs.ss-rhs.ff;
        return lhs.ff>rhs.ff;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n + 1];
        priority_queue<pi,vector<pi>,compare> pq;
        pq.push(mp(1,n));
        ll i=1,mid;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            mid=(p.ff+p.ss)/2;
            a[mid]=i++;
            if(p.ff!=mid)pq.push(mp(p.ff,mid-1));
            if(p.ss!=mid)pq.push(mp(mid+1,p.ss));
        }
        FOR1(i, n) cout << a[i] << " ";
        cout << endl;
    }
}