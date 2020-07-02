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
    int n;
    cin >> n;
    ll a[n];
    ll mx= 0;
    FOR0(i, n) cin >> a[i], mx = max(mx, a[i]);
    if (n == 2){
        cout << (a[0] * a[1])/__gcd(a[0], a[1]);
        return 0;

    }
    bool prime[mx+1]; 
    memset(prime, true, sizeof(prime));
    vi primes; 
    for (int p=2; p*p<=mx; p++) 
    { 
        if (prime[p] == true) 
        { 
            // primes.pb(p);
            for (int i=p*p; i<=mx; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int i = 2; i < mx + 1; i++) if (prime[i]) primes.pb(i);
    int freq[mx + 1];
    mst0(freq);
    int ans = 1;
    
    for (auto x: primes){
        // cout << x << endl;
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; i++){
            // cout << x sp a[i] sp ans << endl;
            if (a[i]%x != 0){
                pq.push(0);
                freq[x]++;
                if (freq[x] == 2) break;
                else continue;
            }
            else{
                int cnt = 0;
                while(a[i]%x == 0){
                    cnt++;
                    a[i]/=x;
                }
                pq.push(cnt);
                // cout << x sp a[i] sp cnt << endl;
            }
           
        }

        if (freq[x] < 2){
            pq.pop();
            ans*= pow(x, pq.top());
            // cout << x sp ans << endl;
        }
    }
    cout << ans << endl;
  

}