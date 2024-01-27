class Solution {
public:
    int kInversePairs(int n, int k) {
         const int MOD = 1000000007;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 2; i <= n; ++i) {
        vector<int> prefixSum(k + 1, 0);
        prefixSum[0] = dp[0];

        for (int j = 1; j <= k; ++j) {
            prefixSum[j] = (prefixSum[j - 1] + dp[j]) % MOD;
            if (j >= i) {
                prefixSum[j] = (prefixSum[j] - dp[j - i] + MOD) % MOD;
            }
        }

        for (int j = 0; j <= k; ++j) {
            dp[j] = prefixSum[j];
        }
    }

    return dp[k];
        
    }
};