
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) &&
                   grid[i][j] == 0 && !vis[i][j]) {

                    vis[i][j] = 1;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto [xi,xj] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int ni = xi + row[k];
                            int nj = xj + col[k];

                            if(ni < 0 || nj < 0 || ni >= n || nj >= m ||
                               vis[ni][nj] || grid[ni][nj] == 1)
                                continue;

                            vis[ni][nj] = 1;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }

        
        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                if(grid[i][j] == 0 && !vis[i][j]) {
                    ans++;
                    vis[i][j] = 1;
                    q.push({i,j});

                    while(!q.empty()) {
                        auto [xi,xj] = q.front();
                        q.pop();

                        for(int k = 0; k < 4; k++) {
                            int ni = xi + row[k];
                            int nj = xj + col[k];

                            if(ni < 0 || nj < 0 || ni >= n || nj >= m ||
                               vis[ni][nj] || grid[ni][nj] == 1)
                                continue;

                            vis[ni][nj] = 1;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }

        return ans;
    }
};
