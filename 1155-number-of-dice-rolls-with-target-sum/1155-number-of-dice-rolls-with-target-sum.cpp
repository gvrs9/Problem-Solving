#define MOD 1000000007

class Solution {
    int dp[31][1001];
private:
    int getRes(int d, int f, int t) {
        if(d == 0 || t == 0) return d == t;
        if(d <= 0 || t <= 0) return 0;
        if(dp[d][t] != -1) return dp[d][t];
        
        int res = 0;

        for(int i = 1; i <= f; i++)
            res = ((res % MOD) + (getRes(d - 1, f, t - i) % MOD)) % MOD;
        
        return dp[d][t] = res;
    }
public:
    int numRollsToTarget(int d, int f, int t) {
        memset(dp, -1, sizeof(dp));
        return getRes(d, f, t);
    }
};