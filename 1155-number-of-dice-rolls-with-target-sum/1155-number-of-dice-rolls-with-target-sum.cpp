#define MOD 1000000007

class Solution {
private:
    int getRes(int d, int f, int t, vector<vector<int> >& dp) {
        if(d == 0 || t == 0) return d == t;
        if(d <= 0 || t <= 0) return 0;
        if(dp[d][t] != -1) return dp[d][t];
        
        int res = 0;

        for(int i = 1; i <= f; i++)
            res = ((res % MOD) + (getRes(d - 1, f, t - i, dp) % MOD)) % MOD;
        
        return dp[d][t] = res;
    }
public:
    int numRollsToTarget(int d, int f, int t) {
        vector<vector<int> > dp(31, vector<int>(1001, -1));
        return getRes(d, f, t, dp);
    }
};