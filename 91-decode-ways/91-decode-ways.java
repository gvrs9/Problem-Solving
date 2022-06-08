class Solution {
    public static Integer[] dp;
    private static int getCnt(String s, int idx) {
        if(idx >= s.length()) return 1;
        if(s.charAt(idx) == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        int cntWay1 = getCnt(s, idx + 1);
        int cntWay2 = 0;
        if(idx < s.length() - 1 && Integer.parseInt(s.substring(idx, idx + 2)) <= 26) cntWay2 = getCnt(s, idx + 2);
        return dp[idx] = (cntWay1 + cntWay2);
    }
    public int numDecodings(String s) {
        dp = new Integer[s.length() + 1];
        Arrays.fill(dp, -1);
        return getCnt(s, 0);
    }
}