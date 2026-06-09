class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        int startCost = (grid[0][0] == 0 ? 0 : 1);
        if (startCost > k) return -1;

        dp[0][0][startCost] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    int val = grid[i][j];
                    int cost = (val == 0 ? 0 : 1);

                    if (j + 1 < n) {
                        int nextVal = grid[i][j+1];
                        int nextCost = (nextVal == 0 ? 0 : 1);

                        if (c + nextCost <= k) {
                            dp[i][j+1][c + nextCost] = max(
                                dp[i][j+1][c + nextCost],
                                dp[i][j][c] + nextVal
                            );
                        }
                    }

                    if (i + 1 < m) {
                        int nextVal = grid[i+1][j];
                        int nextCost = (nextVal == 0 ? 0 : 1);

                        if (c + nextCost <= k) {
                            dp[i+1][j][c + nextCost] = max(
                                dp[i+1][j][c + nextCost],
                                dp[i][j][c] + nextVal
                            );
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m-1][n-1][c]);
        }

        return ans;
    }
};