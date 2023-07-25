class Solution {
    public int[] plusOne(int[] digits) {
        /*
        // Mind Fucked Code. Simply a Bullshit!!
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int i = 0; i < digits.length; i++) {
            ls.add(digits[i]);
        }
        
        
        if(digits[digits.length - 1] != 9) {
            ls.set(ls.size() - 1, ls.get(ls.size() - 1) + 1);
        }else {
            int counter = 0;
            boolean addFlag = false, notNineFound = false;
            for(int i = ls.size() - 1; i >= 0; i--) {
                if(ls.get(i) == 9 && notNineFound == false) {
                    counter++;
                    ls.set(i, 0);
                    addFlag = true;
                }else if(addFlag) {
                    ls.set(i, ls.get(i) + 1);
                    addFlag = false;
                    notNineFound = true;
                }
            }
            
            if(counter == ls.size()) {
                ls.add(0, 1);
            }
        }
        
        return ls.stream().mapToInt(i -> i).toArray();
        */
        
        int n = digits.length;
        
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        int[] newLargeInteger = new int[n + 1];
        newLargeInteger[0] = 1;
        
        return newLargeInteger;
        
    }
}