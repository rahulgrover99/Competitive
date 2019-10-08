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


int main(){
    int n, t, c, k1, k2, f, s;
    queue<int> first, second;
    cin >> n >> k1;
    FOR0(i,k1){
        cin >> t;
        first.push(t);
    }
    cin >> k2;
    FOR0(i,k2){
        cin >> t;
        second.push(t);
    }
    while (c < 100000 and first.size() and second.size()){
        f = first.front();
        first.pop();
        s = second.front();
        second.pop();
        if (f > s){
            first.push(s);
            first.push(f);
        }
        else{
            second.push(f);
            second.push(s);
        }
        c++;
    }
    if (second.empty()) cout << c << " 1" << endl;
    else if (first.empty()) cout << c << " 2" << endl;
    else cout << -1 << endl;
    return 0;
}