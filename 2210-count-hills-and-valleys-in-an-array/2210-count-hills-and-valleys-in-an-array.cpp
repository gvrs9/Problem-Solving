/*class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Storing index in the prevIndex.
        int cnt = 0, prevIndex = 0;
        
        // [2,4,3,1,1,1,1,1,6,5,1,3,2]
                             int temp = 0;
        for(int i = 1; i < (int)nums.size() - 1; i++) {
            if((nums[i] > nums[prevIndex] && nums[i] > nums[i + 1]) || (nums[i] < nums[prevIndex] && nums[i] < nums[i + 1])) {
                temp = prevIndex;
                cnt++, prevIndex = i;
                if(prevIndex == 7) cout << "temp --> " << temp << " " << "i --> " << i << " i + 1 --> " << i + 1 << " ";
            }
            cout << prevIndex << "\n";
        }
        
        return cnt;
    }
};
*/

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // Storing value in the prev.
        int count = 0, prev = nums[0];
        
        for(int i = 1; i < (int)nums.size() - 1; i++) {
            // if((nums[i] > prev && nums[i] > nums[i + 1]) || (nums[i] < prev && nums[i] < nums[i + 1])) count++, prev = nums[i];
            if((nums[i] > prev && nums[i] > nums[i + 1]) || (nums[i] < prev && nums[i] < nums[i + 1])) count++;
            if(nums[i] != nums[i + 1]) {
                // cout << nums[i] << "\n";
                prev = nums[i]; // We don't need this condition here. We can simply update the prev in the 1st condition as we only update prev when we are not looking at duplicates.
            }
        }
        return count;
    }
};
