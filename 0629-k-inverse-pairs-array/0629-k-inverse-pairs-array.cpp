class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int x = 0; x <= min(j, i - 1); ++x) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }

    return dp[n][k];
        
    }
};