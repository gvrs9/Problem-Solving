//{ Driver Code Starts
//Initial Template for Java

//Initial Template for Java

import java.io.*;
import java.util.*;

// } Driver Code Ends
//User function Template for Java

public class Solution {
    static int CountPairs(int a[], int n) {
        /*
         * // TLE!! O(n^2) -> T.C
         * int count = 0;
         * for(int i = 0; i < n; i++) {
         * for(int j = 0; j < n; j++) {
         * if(i > j && ((a[i] + a[j]) < (a[i] * a[j]))) {
         * // System.out.println(i + " " + j);
         * count++;
         * }
         * }
         * }
         * return count;
         */

        // O(N) -> T.C
        // Wtf might be your expression seeing the return statement!! ok, let's discuss
        // firstly the given case is A[i] + A[j] < A[i] * A[j]. So this tells us that,
        // we have, 4 cases. when A[i] = 0, 1, 2, greater than 2.
        // When A[i] = 0, no pairs can be made using this.
        // When A[i] = 1, also no pairs can be formed. Don't be lazy!! C'mon substitute
        // and check for yourself
        // When A[i] = 2 and A[i] > 2 then, internally we will now have 2 internal
        // cases. They are:
        // when A[i] = 2 and A[j] > 2 and A[i] > 2 and A[j] >= 2. So these two cases
        // will definitely have valid pairs forming. Remember we can't have A[j] as in
        // {0, 1} which will result in no pairs as similar to the above mentioned A[i] =
        // {0, 1} cases.
        // Since we now know that (A[i] = 2 and A[j] > 2 and A[i] > 2 and A[j] >= 2) can
        // give valid pairs, How will we find the no. of pairs?? Simple, we need some
        // math formula like combinations formula.
        // firstly we will count the no.of two's and no.of greater than two's. Then for
        // example, if we have the array [1, 4, 7, 2, 11], twoCount = 1 and
        // twoGreaterCount = 3. So we can form 3 pairs using just the {4, 7, 11} -> [{4,
        // 7}, {4, 11}, {7, 11}] this can be achieved using n*(n - 1)/2 formula sicne
        // order doesn't matter and we need to choose. n in that formula is
        // twoGreaterCount.
        // And now we also need to check how many pairs will "two(as in number 2)" form
        // using the {4, 7, 11} set. So this is (twoCnt * twoGreaterCnt). Example here
        // in the above array [1, 4, 7, 2, 11], twoCount = 1 and twoGreaterCount = 3. So
        // no.of pairs formed using one 2 is [{2, 4}, {2, 7}, {2, 11}] => 1(one 2) *
        // twoGreaterCount. So for m two's -> m * twoGreaterCount. Here m = twoCount.
        // Now finally we need to add both of them forming the final formula ->
        // ((twoCount * twoGreaterCount) + ((twoGreaterCount * (twoGreaterCount - 1)) /
        // 2));
        int twoCount = 0, twoGreaterCount = 0;
        for (int i : a) {
            if (i > 2)
                twoGreaterCount++;
            else if (i == 2)
                twoCount++;
        }
        return ((twoCount * twoGreaterCount) + ((twoGreaterCount * (twoGreaterCount - 1)) / 2));
    }
}

// { Driver Code Starts.

// Driver class
class Array {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(a1[i]);
            }
            Solution ob = new Solution();
            int ans = ob.CountPairs(a, n);
            System.out.println(ans);

        }
    }
}

// } Driver Code Ends