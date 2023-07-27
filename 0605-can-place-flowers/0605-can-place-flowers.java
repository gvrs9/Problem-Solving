class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        /* // one way of doing. Unnecessary code is present!!
            if(n == 0) return true;
            if(flowerbed.length == 1) {
                if(n > 1) return false;
                if(flowerbed[0] == 0) return true;
                return false;
            }
            for(int i = 0; i < flowerbed.length; i++) {
                if(n > 0 && flowerbed[i] == 0) {
                    if(i - 1 >= 0 && flowerbed[i - 1] == 0 && i + 1 < flowerbed.length && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }else if(i - 1 < 0 && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }else if(i + 1 == flowerbed.length && flowerbed[i - 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }else if(n == 0) {
                    return true;
                }
            }
            return (n > 0) ? false : true;
        */
        if(n == 0) return true;
        for(int i = 0; i < flowerbed.length && n > 0;) {
            if(flowerbed[i] == 0) {
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                int next = (i == flowerbed.length - 1) ? 0 : flowerbed[i + 1];
                if(prev == 0 && next == 0) {
                    // flowerbed[i] = 1;
                    i += 2;
                    n--;
                    continue;
                }
            }
            i++;
        }
        return n == 0;
    }
}
