string Solution::multiple(int A) {
    if (A==0) return "0";
    if (A==1) return "1";
    string ans = "";
    vector< bool > visited(A + 1);
    vector< int > parent(A + 1);
    vector< char > src(A + 1);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    parent[1] = -1;
    src[1] = '1';
    while(!q.empty()){
        int rem = q.front();
        q.pop();
        if(rem == 0){
            while(rem != -1){
                ans.push_back(src[rem]);
                rem = parent[rem];
            }
            //ans.push_back('1');
            reverse(ans.begin(), ans.end());
            return ans;
        }
        int l = (rem*10)%A;
        int r = (rem*10+1)%A;
        if (!visited[l]){
            visited[l] = true;
            parent[l] = rem;
            q.push(l);
            src[l] = '0';
        }
        if (!visited[r]){
            visited[r] = true;
            parent[r] = rem;
            q.push(r);
            src[r] = '1';
        }
    }
}