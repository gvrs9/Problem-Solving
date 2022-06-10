class Solution {
private:
    void getSubsets(vector<int> nums,int index,vector<int> output,vector<vector<int> >& ans) {
        //Base Condition
        if(index == (int)nums.size()) {
            ans.push_back(output);
            return;
        }
        /*
        //exclude
        getSubsets(nums,index + 1,output,ans);
        //include
        output.push_back(nums[index]);
        getSubsets(nums,index + 1,output,ans);
        */
       //include
       output.push_back(nums[index]);
       getSubsets(nums,index + 1,output,ans);
       //exclude
       output.pop_back();
       getSubsets(nums,index + 1,output,ans); 
    }
private:
    void getSubsetsRecursive(vector<int> nums,int index,vector<int> output,vector<vector<int> >& ans) {
        ans.push_back(output);
        for(int i=index;i<(int)nums.size();i++) {
            output.push_back(nums[i]);
            getSubsetsRecursive(nums,i + 1,output,ans);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> output;
        // getSubsets(nums,0,output,ans);
        getSubsetsRecursive(nums,0,output,ans);
        return ans;
    }
};