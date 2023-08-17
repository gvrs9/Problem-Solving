/*
Problem Link : "https://www.codingninjas.com/studio/problems/sorted-array_6613259"
Problem Statement : 
Given two sorted arrays a and b of size n and m respectively, return the union of the arrays. 
The union of two sorted arrays can be defined as an array consisting of the common and the distinct elements of the two arrays. 
The final array should be sorted in ascending order. 
Note: that arrays 'a' and 'b' may contain duplicate elements, but the union array must contain unique elements.

Example : 
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]

Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
Distinct elements in ‘a’ are: [1, 4, 6]
Distinct elements in ‘b’ are: [5]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]

---------------------------------------------------------

Sample Input 1 :
5 3
1 2 3 4 6
2 3 5
Sample Output 1 : 
1 2 3 4 5 6

Explanation Of Sample Input 1 :
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]

Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
Distinct elements in ‘a’ are: [1, 4, 6]
Distinct elements in ‘b’ are: [5]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]

---------------------------------------------------------

Sample Input 2 :
4 3
1 2 3 3
2 2 4
Sample Output 2 :
1 2 3 4

Explanation Of Sample Input 2 :
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 3]
‘b’ = [2, 2, 4]

Output: [1, 2, 3, 4]

Explanation: Common elements in ‘a’ and ‘b’ are: [2]
Distinct elements in ‘a’ are: [1, 3]
Distinct elements in ‘b’ are: [4]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4]

---------------------------------------------------------

Constraints : 
1 <= 'n', 'm' <= 10^5
-10^9 <= 'a'[i], 'b'[i] <= 10^9

Time Limit: 1 sec
*/

import java.util.*;
public class Solution {
    public static List< Integer > sortedArray(int []a, int []b) {
        // Write your code here
        int n = a.length, m = b.length;
        int i = 0, j = 0;
        List <Integer> l = new ArrayList<>();
        while (i < n && j < m) {
            while ((i > 0 && i < n) && a[i - 1] == a[i]) i++;
            while ((j > 0 && j < m) && b[j - 1] == b[j]) j++;
            if (i < n && j < m) {
                if (a[i] < b[j]) {
                    l.add(a[i]); i++;
                }else if (a[i] > b[j]) {
                    l.add(b[j]); j++;
                }else {
                    l.add(a[i]); i++; j++;
                }
            }
        }

        while (i < n) {
            while ((i > 0 && i < n) && a[i - 1] == a[i]) i++;
            if (i < n) l.add(a[i++]);
        }
        while (j < m) {
            while ((j > 0 && j < m) && b[j - 1] == b[j]) j++;
            if(j < m) l.add(b[j++]);
        }

        return l;
    }
}
