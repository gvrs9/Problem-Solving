class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // [1,1,2,2,3,3,4,5,5,6,6,7,7,8,8]
        // if mid is odd and arr[mid - 1] == arr[mid], then do not visit that [lo, mid - 1] space. That means reduce that space.
        // if mid is odd and arr[mid + 1] == arr[mid], then do not visit that [mid + 1, hi] space. That means reduce that space.
        // If mid is even and arr[mid - 1] == arr[mid], then visit that [lo, mid - 1] space.
        // If mid is even and arr[mid + 1] == arr[mid], then visit that [mid + 1, hi] space.
        // If arr[mid] != arr[mid -1] && arr[mid] != arr[mid + 1] then return that arr[mid].
        // [1, 2, 2, 3, 3, 4, 4, 5, 5]
        
        // [1, 1, 2, 2, 3, 3, 4, 4, 5]
        
        /*
            [1, 2, 2, 3, 3, 4, 4, 5, 5]
            [1, 1, 2, 2, 3, 3, 4, 4, 5]
            [1,1,2,2,3,3,4,5,5,6,6,7,7,8,8]
        */
        
        int n = nums.size();
        if(n == 1) return nums[0];
        int lo(0), hi(n - 1);
        /*while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(mid - 1 > 0 && mid + 1 < n && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }else if(mid - 1 < 0 && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            }else if(mid + 1 > n && nums[mid - 1] != nums[mid]) {
                return nums[mid];
            }else if(mid & 1) { // if mid is odd
                if(mid - 1 > 0 && nums[mid - 1] == nums[mid]) {
                    lo = mid + 1;
                }else if(mid + 1 < n && nums[mid + 1] == nums[mid]) {
                    hi = mid - 1;
                }
            }else if((mid & 1) == 0) { // if mid is even
                if(mid - 1 > 0 && nums[mid - 1] == nums[mid]) {
                    hi = mid - 1;
                }else if(mid + 1 < n && nums[mid + 1] == nums[mid]) {
                    lo = mid + 1;
                }
            }
        }
        return nums[lo];*/
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            // cout << "middi --> " << mid << "\n";
            if(mid - 1 > 0 && mid + 1 < n && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }else if(mid - 1 < 0 && nums[mid + 1] != nums[mid]) {
                return nums[mid];
            }else if(mid + 1 > n && nums[mid - 1] != nums[mid]) {
                return nums[mid];
            }else if(mid & 1) { // if mid is odd
                if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                    lo = mid + 1;
                }else if(mid + 1 < n && nums[mid + 1] == nums[mid]) {
                    hi = mid - 1;
                }else {
                	return nums[mid];
                }
                // cout << lo << " " << hi << "\n";
            }else if((mid & 1) == 0) { // if mid is even
                if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                    hi = mid - 1;
                }else if(mid + 1 < n && nums[mid + 1] == nums[mid]) {
                    lo = mid + 1;
                }else {
                	return nums[mid];
                }
                // cout << lo << " " << hi << "\n";
            }
        }
        return nums[lo];
    }
};