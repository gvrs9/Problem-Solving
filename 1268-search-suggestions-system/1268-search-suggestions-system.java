class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {

        /**
        // Brute Force

        The expected worst-case time complexity of the given code is O(n^2), where n is the number of products.

        Here's the breakdown of the time complexity:

        1. Sorting the products array using Arrays.sort: O(n log n)
        The code sorts the products array using a comparison-based sorting algorithm, which has a time complexity of O(n log n).

        2. Iterating over each character in the searchWord: O(m), where m is the length of the searchWord.
        The outer loop iterates over each character in the searchWord, which takes O(m) time.

        3. Nested loop iterating over the products array: O(n)
        The inner loop iterates over the products array, which has n elements.

        4. Comparing characters in the nested loop: O(k), where k is the average length of the product strings.
        The inner while loop compares characters between the product string and the tempString. In the worst case, it iterates over k characters.

        Therefore, the overall time complexity is O(n log n + m * n * k). In the worst case, when m is relatively large compared to n and k, the dominant term is n * m * k, resulting in a time complexity of O(n^2).

        int n = products.length;
        List<List<String>> ans = new ArrayList<List<String>>();
        Arrays.sort(products);
        String tempString = "";

        for(int i = 0; i < searchWord.length(); i++) {
            List<String> list = new ArrayList<>();
            tempString += searchWord.charAt(i);
            int tempStringLength = tempString.length();
            int maxProductsStringCnt = 0;

            for(int j = 0; j < n && maxProductsStringCnt < 3; j++) {
                int productsArrayIndividualLength = products[j].length();
                int prodArrayIter = 0, tempStringIter = 0;
                while(prodArrayIter < productsArrayIndividualLength && tempStringIter < tempStringLength && products[j].charAt(prodArrayIter) == tempString.charAt(tempStringIter)) {
                    prodArrayIter++; 
                    tempStringIter++;
                }
                if(tempStringIter == tempStringLength) {
                    list.add(products[j]);
                    maxProductsStringCnt++;
                }
            }

            ans.add(list);
        }
        return ans;


        */

        int n = products.length;
        int m = searchWord.length();
        List<List<String>> ans = new ArrayList<List<String>>();
        Arrays.sort(products);
        String tempPrefix = new String();
        int start = 0, bsStart = 0;
        for(int i = 0; i < m; i++) {
            tempPrefix += searchWord.charAt(i);

            start = lower_bound(products, bsStart, tempPrefix);

            List<String> list = new ArrayList<>();
            for(int j = start; j < Math.min(start + 3, n); j++) {
                // consider if products[j].length = 2 and prefix.length = 3, we don't want that string rigth!! And we also check whether the products[j] string is equal to the prefix or not using the substring method. If equal, we continue. If not equal, we exit the loop since we do not want that substring anyway. And we do this operation "||"(Logical OR operator) to ensure either case when not satisfied, breaks the loop!! 
                if(products[j].length() < tempPrefix.length() || !products[j].substring(0, tempPrefix.length()).equals(tempPrefix)) break;
                list.add(products[j]);
            }
            ans.add(list);
        }
        return ans;
    }

    private static int lower_bound(String[] products, int start, String word) {
        int i = start, j = products.length, mid;
        while(i < j) {
            mid = (i + j) / 2;
            // refer this for compareTo(). "https://www.w3schools.com/java/ref_string_compareto.asp#:~:text=The%20method%20returns%200%20if,other%20string%20(more%20characters)."
            if(products[mid].compareTo(word) >= 0) j = mid;
            else i = mid + 1;
        }
        return i;
    } 
}