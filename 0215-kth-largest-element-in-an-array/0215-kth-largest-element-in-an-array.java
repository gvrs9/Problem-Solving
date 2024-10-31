class Solution {
    public int findKthLargest(int[] arr, int K) {
        int n = arr.length;
        if (n == 0 || K > n) {
	        throw new IllegalArgumentException("Array is empty or K is greater than the number of elements.");
	    }
		
		PriorityQueue<Integer> priorityQueue = new PriorityQueue<>();
		
		for(int i = 0; i < n; i++) {
			priorityQueue.add(arr[i]);
			
			if(priorityQueue.size() > K) {
				priorityQueue.poll();
			}
		}
		
		return priorityQueue.peek();
    }
}