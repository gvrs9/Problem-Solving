class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] hash = new int[26];
        Arrays.fill(hash, 0);
        for(int i = 0; i < text.length(); i++) hash[text.charAt(i) - 'a']++;
        // for(char x : text) hash[x - 'a']++;
        int banMin = Math.min(Math.min(hash['b' - 'a'], hash['a' - 'a']), hash['n' - 'a']);
        if(banMin < 1) return 0;
        int loMin = Math.min(hash['l' - 'a'], hash['o' - 'a']) / 2;
        if(loMin < 1) return 0;
        return (banMin < loMin) ? banMin : loMin;
    }
}