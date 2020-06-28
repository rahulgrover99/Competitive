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

int main() {
    ll n, k;
    cin >> n >> k;
    priority_queue< ll,vector<ll> ,greater< ll > > pa, pb, pab;
    ll tim, a, b;
    for(int i = 1; i <= n; i++){
        cin >> tim >> a >> b;
        if(a == 1 && b == 1){
            pab.push(tim);
        }else if(a == 1){
            pa.push(tim);
        }else if(b == 1){
            pb.push(tim);
        }
    }
    ll cnt = 0, sum = 0;
    while((cnt < k) && !pa.empty() && !pb.empty() && !pab.empty()){
        ll a = pa.top();
        ll b = pb.top();
        ll ab = pab.top();
        if(ab <= (a+b)){
            sum += ab;
            pab.pop();
        }else{
            sum += (a+b);
            pa.pop();
            pb.pop();
        }
        cnt++;
    }
    if(cnt == k){
        cout << sum << endl;
        return 0;
    }
    if(pa.empty() || pb.empty()){
        while(cnt < k && !pab.empty()){
            sum += pab.top();
            pab.pop();
            cnt++;
        }
        if(cnt == k){
            cout << sum << endl;
            return 0;
        }else{
            cout << "-1" << endl;
            return 0;
        }
    }
    if(pab.empty()){
        while(cnt < k && !pa.empty() && !pb.empty()){
            sum += pa.top();
            sum += pb.top();
            pa.pop();
            pb.pop();
            cnt++;
        }
        if(cnt == k){
            cout << sum << endl;
            return 0;
        }else{
            cout << "-1" << endl;
            return 0;
        }
    }
}