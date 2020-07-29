class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        queue<pair<int, int> > qu;
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) cnt++;
                if (grid[i][j] == 2) qu.push({i, j});
            }
        }
        if(cnt == 0) return 0;
        int count = 0;
        int x1[] = {1, -1, 0, 0};
        int y1[] = {0, 0, -1, 1};
      
        
        while(!qu.empty()) {
            ++count;
            int size = qu.size();
        
            for(int i = 0 ; i < size ; i++) {
            
                auto point = qu.front();
                qu.pop();
                for (int k = 0; k < 4; k++){
                    int x = point.first + x1[k];
                    int y = point.second + y1[k];
                   
                    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || grid[x][y] == 2) continue;
                   
                    grid[x][y] = 2;
                    
                    qu.push({x , y});
                    cnt--;
                }
            }
        }
        return cnt == 0 ? count-1 : -1;

    }
};