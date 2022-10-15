//{ Driver Code Starts
//Initial Template for Java


//Initial Template for Java


import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function Template for Java


public class Solution { 
    static int CountPairs (int a[], int n) {
    /* 
        // TLE!! O(n^2) -> T.C
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i > j && ((a[i] + a[j]) < (a[i] * a[j]))) {
                    // System.out.println(i + " " + j);
                    count++;
                }
            }
        }
        return count;
    */
    
        // O(N) -> T.C
        int twoCount = 0, twoGreaterCount = 0;
        for(int i : a) {
            if(i > 2) twoGreaterCount++;
            else if(i == 2) twoCount++;
        }
        return ((twoCount * twoGreaterCount) + ((twoGreaterCount * (twoGreaterCount - 1)) / 2));
    }
}


//{ Driver Code Starts.

// Driver class
class Array {
    
    // Driver code
	public static void main (String[] args) throws IOException{
		// Taking input using buffered reader
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testcases = Integer.parseInt(br.readLine());
		// looping through all testcases
		while(testcases-- > 0){
		    int n=Integer.parseInt(br.readLine());
		    String line1 = br.readLine();
		    String[] a1 = line1.trim().split("\\s+");
		    int a[]=new int[n];
		    for(int i=0;i<n;i++)
		    {
		        a[i]=Integer.parseInt(a1[i]);
		    }
		    Solution ob=new Solution();
		    int ans=ob.CountPairs(a,n);
		    System.out.println(ans);
		    
		}
	}
}

// } Driver Code Ends