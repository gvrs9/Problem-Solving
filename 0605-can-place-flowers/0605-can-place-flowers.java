class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(n == 0) return true;
        if(flowerbed.length == 1) {
            if(n > 1) return false;
            if(flowerbed[0] == 0) return true;
            return false;
        }
        for(int i = 0; i < flowerbed.length; i++) {
            if(n > 0 && flowerbed[i] == 0) {
                // System.out.println(i + " " + n);
                if(i - 1 >= 0 && flowerbed[i - 1] == 0 && i + 1 < flowerbed.length && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                    System.out.println(i + " " + n + " " + flowerbed[i]);
                }else if(i - 1 < 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                    System.out.println(i + " " + n + " " + flowerbed[i]);
                }else if(i + 1 == flowerbed.length && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                    System.out.println(i + " " + n + " " + flowerbed[i]);
                }
            }else if(n == 0) {
                return true;
            }
        }
        return (n > 0) ? false : true;
    }
}