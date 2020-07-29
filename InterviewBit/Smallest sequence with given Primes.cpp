#define ll long long

vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    map<ll, int> mp;
    ll x = 1;
    if (mp[x*A] != 1){
        mp[x*A] = 1;
        pq.push(x*A);
    }
    if (mp[x*B] != 1){
        mp[x*B] = 1;
        pq.push(x*B);
    }
    if (mp[x*C] != 1){
        mp[x*C] = 1;
        pq.push(x*C);
    }
    int tmp = D;
    vector<int> ans;
    while(ans.size() < D){
        ll x = pq.top();
        ans.push_back(x);
        pq.pop();
        if (pq.size() > 2*tmp) continue;
        if (mp[x*A] != 1){
            mp[x*A] = 1;
            pq.push(x*A);
        }
        if (mp[x*B] != 1){
            mp[x*B] = 1;
            pq.push(x*B);
        }
        if (mp[x*C] != 1){
            mp[x*C] = 1;
            pq.push(x*C);
        }

    }
    return ans;
}
