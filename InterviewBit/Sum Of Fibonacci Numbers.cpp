int Solution::fibsum(int A) {
    vector< int > fibs{1, 1};
    for(int i = 2; fibs.back() < A; ++i){
        fibs.push_back(fibs[i - 1] + fibs[i - 2]);
    }
    int ans = 0;
    int n = fibs.size() - 1;
    while(n >= 0){
        ans += (A / fibs[n]);
        A -= (A / fibs[n]) * fibs[n];
        --n;
    }
    
    return ans;
    
}
