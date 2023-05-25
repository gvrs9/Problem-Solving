class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        int n = products.length;
        List<List<String>> ans = new ArrayList<List<String>>();
        Arrays.sort(products);
        String tempString = "";

        for(int i = 0; i < searchWord.length(); i++) {
            List<String> list = new ArrayList<>();
            tempString += searchWord.charAt(i);
            System.out.println("hi");
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
    }
}