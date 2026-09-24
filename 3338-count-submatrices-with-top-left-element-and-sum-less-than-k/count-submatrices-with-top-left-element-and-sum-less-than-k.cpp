class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pre(n, vector<int>(m));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                pre[i][j] = grid[i][j];

                if(i > 0)
                    pre[i][j] += pre[i-1][j];

                if(j > 0)
                    pre[i][j] += pre[i][j-1];

                if(i > 0 && j > 0)
                    pre[i][j] -= pre[i-1][j-1];

                if(pre[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};;