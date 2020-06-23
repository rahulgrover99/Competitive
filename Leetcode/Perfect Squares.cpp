#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        
        for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j*j <= n; j++){
                if (i - j*j < 0) break;
                if (dp[i -j*j] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-j*j] + 1);
                }
            }
        }
        return dp[n];
    }
};


int main(){
    for (int i = 1; i <= 20; i++){
        auto x = Solution();
        cout << i << " " << x.numSquares(i) << endl;
    }
}
