class Solution {
    public List<Integer> getRow(int rowIndex) {
        Integer[] arr = new Integer[rowIndex + 1];
        Arrays.fill(arr, 0);
        arr[0] = 1;
        
        for(int i = 1; i < arr.length; i++) {
            for(int j = i; j >= 1; j--) {
                arr[j] += arr[j - 1];
            }
        }
        
        return Arrays.asList(arr);
    }
}