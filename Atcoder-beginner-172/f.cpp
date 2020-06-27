#include <bits/stdc++.h>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define FORl(i, l, n) for (int i = l; i < n; i++)
using namespace std;
#define pi pair<ll, ll>
#define pb push_back
#define ll long long
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define mst0(x) memset(x, 0, sizeof(x));
#define vi vector<ll>
#define sync                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);
#define endl '\n'
#define sp << " " <<
#define intmax 1e14
ll mod = 1e9 + 7;

ll power(ll num, ll g, ll mod)
{
	if (g == 0)
		return 1;
	if (g % 2 == 1)
		return (num * power((num * num) % mod, g / 2, mod)) % mod;
	return power((num * num) % mod, g / 2, mod);
}

bool flag = true;
vector<int> poss;
ll final_a, final_b;
void compute(unsigned ll S, unsigned ll X) 
{ 
    unsigned ll A = (S - X)/2; 
    unsigned ll a = 0, b = 0; 
  
    for (unsigned ll i=0; i<8*sizeof(S); i++) 
    { 
        unsigned ll Xi = (X & (1LL << i)); 
        unsigned ll Ai = (A & (1LL << i)); 
        if (Xi == 0 && Ai == 0) 
        { 
            // Let us leave bits as 0. 
        } 
        else if (Xi == 0 && Ai > 0) 
        { 
            a = ((1LL << i) | a);  
            b = ((1LL << i) | b);  
        } 
        else if (Xi > 0 && Ai == 0) 
        { 
            a = ((1LL << i) | a);  
            poss.push_back(i);
            // We leave i-th bit of b as 0. 
        } 
        else // (Xi == 1 && Ai == 1) 
        { 
            flag = false;
            return; 
        } 
    } 
    final_a = a;
    final_b = b;
    // cout << "a = " << a << endl << "b = " << b; 
} 

set<pi> sols;

void rec(ll a, ll b, int ind){
    if (ind == poss.size()){
        sols.insert({a, b});
        return;
    }
    int pw = poss[ind];
    // sols.insert({a, b});
    rec(a, b, ind + 1);
    b = ((1LL << pw) | b);
    a = ((1LL << pw) ^ a);
    rec(a, b, ind + 1);
}


int main() {
    int n;
    cin >> n;
    ll a[n];
    FOR0(i, n) cin >> a[i];
    ll xor_val = 0;
    for (int i = 2; i < n; i++) xor_val^=a[i];
    ll sum = a[0] + a[1];
    compute(sum, xor_val);

    if (flag == false){
        cout << -1;
        return 0;
    }
    ll f = a[0];
    ll s = a[1];
    ll ans = 1e17;

    rec(final_a, final_b, 0);
    for (auto x : sols){
        if (x.ff > f || x.ff == 0) continue;
        ans = min(ans, f - x.ff);
    }
    for (auto x : sols){
        if (x.ss > f || x.ss == 0) continue;
        ans = min(ans, f - x.ss);
    }
    if (ans == 1e17){
        cout << -1  << endl;
        return 0;
    }
    cout << ans << endl;
}