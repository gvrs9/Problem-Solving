class Solution {
    public boolean wordPattern(String pattern, String str) {
        String[] words = str.split(" ");
        if (words.length != pattern.length())
            return false;
        Map index = new HashMap(); // This is the correct way. Try tweaking and the code breaks as it will throw an error of Incompatible types!!
        for (Integer i=0; i<words.length; ++i)
            // HashMap put : If an existing key is passed then the previous value gets returned. If a new pair is passed, then NULL is returned.
            if (index.put(pattern.charAt(i), i) != index.put(words[i], i)) {
                return false;
            }
        return true;
    }
}