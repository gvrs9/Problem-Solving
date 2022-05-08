class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        // Remember that this solution only works for finding the minimum of this rotated sorted array but not the exact pivot(exact index of the minimum element in rotated sorted array having duplicates or not having duplicates). it gives right minimum element but wrong pivot for [1, 1, 1, 1, 2, 1, 1]. It gives mini ele as 1 but gives pivot as 0 which is wrong. It should be 5!!
        if(nums.size() == 0) return INT_MIN;
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end]) start = mid + 1;
            else if(nums[mid] < nums[end]) end = mid;
            else end--;
        }
        // cout << start << " " << end <<"\n";
        return nums[start];
        */
        
        //This works. it gives perfect pivot also along with mini ele for the test cases!!
        if(nums.size() == 0) return INT_MIN;
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end]) start = mid + 1;
            else if(nums[mid] < nums[end]) end = mid;
            else {
                if(end != 0 && nums[end] >= nums[end - 1]) end--;
                else {
                    cout << start << " " << end <<"\n";
                    return nums[end];
                }
            }
        }
        cout << start << " " << end <<"\n";
        return nums[start];
    }
};