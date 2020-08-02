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

const int
	MAXN = 500005,
	MAXLGN = 20;
 
int N, Q;
map<int, int> pos;
int tree[MAXN];
int cant;
struct node {
	int val, L, R, size;
} segtree[2 * MAXN * MAXLGN];
 
int build( int lo, int hi ) {
	if ( lo > hi ) return 0;
	int idx = ++cant;
	int mid = ( lo + hi ) / 2;
	segtree[idx] = (node){ mid, build( lo, mid - 1 ), build( mid + 1, hi ), 0 };
	return idx;
}
 
int update( int x, int val, int amount ) {
	if ( x == 0 ) return 0;
	int idx = ++cant;
	int L = segtree[x].L;
	int R = segtree[x].R;
	if ( val < segtree[x].val ) L = update( L, val, amount );
	if ( val > segtree[x].val ) R = update( R, val, amount );
	segtree[idx] = (node){ segtree[x].val, L, R, segtree[x].size + amount };
	return idx;
}
 
int query( int x, int val ) {
	if (val < segtree[x].val)
		return query( segtree[x].L, val ) + segtree[x].size -	segtree[ segtree[x].L ].size;
 
	if (val > segtree[x].val)
		return query( segtree[x].R, val );
 
	return segtree[x].size - segtree[ segtree[x].L ].size;
}
 
int main() {
	cin >> N;
    cin >> Q;
	tree[0] = build( 1, N );
	FOR1(i, N) {
		int x, posx;
		cin >> x;
        posx = pos[x];
		if (posx != 0) tree[i] = update( update( tree[i - 1], posx, -1 ), i, +1 );
		else tree[i] = update( tree[i - 1], i, +1 );
		pos[x] = i;
	}
 
	while (Q--) {
		int lo, hi;
		cin >> lo >> hi;
		cout << query( tree[hi], lo ) << endl;
	}
 
}