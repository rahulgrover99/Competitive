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
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if (n== 1) {
            cout << 0 << endl;
            continue;
        }
        int twos = 0, three= 0;
        while(1){
            if (n%2== 0){
                twos++;
                n/=2;
            }
            else break;
        }
        while(1){
            if (n%3== 0){
                three++;
                n/=3;
            }
            else break;
        }
        if (n != 1 || three < twos){
            cout << -1 << endl;
            continue;
        }
        else {
            cout << (three-twos) + three << endl;
        }

    }

}