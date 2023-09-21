class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        stack<int> stk;
        
        for(int i = nums2.size() - 1; i >=0; i--) { // First creating all the nges for all the elements in the nums2[] and storing them in a map.
            int currElement = nums2[i];
            while(!stk.empty() && currElement > stk.top()) stk.pop();
            int res = stk.empty() ? -1 : stk.top();
            umap[nums2[i]] = res;
            stk.push(nums2[i]);
        }
        
        for(int i = 0; i < (int)nums1.size(); i++) ans[i] = umap[nums1[i]];
        
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
//         1. Monotonic Stack Concept is used to optimize!!
//         2. Must Read!! https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack
//         3. https://www.geeksforgeeks.org/introduction-to-monotonic-stack-data-structure-and-algorithm-tutorials/
//         4. https://www.youtube.com/watch?v=Dq_ObZwTY_Q&pp=ygUPbW9ub3RvbmljIHN0YWNr
//         5. https://www.youtube.com/watch?v=TunTV2-griM (Fraz)
//         6. https://www.youtube.com/watch?v=cGf_3SgXwWk&pp=ygUPbW9ub3RvbmljIHN0YWNr (Fraz Basic + Advanced)
//         7. https://www.youtube.com/watch?v=J7Ll0I-GSwA&pp=ygUTbW9ub3RvbmUgc3RhY2sgZnJheg%3D%3D (Basic + Advanced)
//         8. https://www.youtube.com/watch?v=68a1Dc_qVq4&pp=ygUTbW9ub3RvbmUgc3RhY2sgZnJheg%3D%3D (Neetcode's explanation to this problem)
        
        
        // Time Complexity is O(n + m) and Space Complexity is O(n).
        
        // Here our idea is to maintain a monotonically decreasing stack for the elements that we need to check the nge for i.e, nums1[]. Suppose we take the case nums1 = [4,1,2] and nums2 = [2,1,3,4]. So, lets say we started at 2 in nums2[]. So, we k/t 2 is present in the nums1[] so we need to find out the nge of 2. we now look at the next value 1 and we k/t 1 is less than 2 so it's not the nge. then we look at the next value i.e., 3 and it is indeed greater than 2 i.e., we found nge for 2 i.e., 3. And now we can add this 3 to the ans[]. Wait!! Hold on bro!! If 3 is nge of 2 and 1 has also nge as 3, provided, 1 is in the nums1[]. So this is the case for any number of values. Suppose we have some other number like 0 in btw 1 and 3 i.e., nums2 = [2,1,0,3,4], Since we know 1 and 0 are not greater than 2 and when we reach 3, 3 is greater than all of them i.e., 2,1,0 and that 1,0 are less than 2. So, if we are finding nge for 2, we are also finding nge for 1 and 0 as well. So here the `Stack` comes handy because, we want to remember all the values.
        
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums1.size(); i++) umap[nums1[i]] = i;
        
        stack<int> stk; // Here we are using monotonically decreasing stack!!
        for(int i = 0; i < (int)nums2.size(); i++) {
            int currElement = nums2[i];
            // we want to know if this currElement is the nge for any previous values that could be on our stack;
            while(!stk.empty() && currElement > stk.top()) { // so currElement is the nge here.
                int value = stk.top(); // pop the top element in the stack and store its value in a variable.
                stk.pop();
                // find the index of the value through the hashmap.
                int idx = umap[value];
                // Now set the nge in the idx position of the ans.
                ans[idx] = currElement;
            }
            
            // check if currElement is in the hashmap so that, if its there then since we need to find nge for it(currElement) too now, we will then push that currElement in the stack.
            if(umap.find(currElement) != umap.end()) stk.push(currElement);
        }
        
        return ans;
    }
};
*/


/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force!! O(n*m) -> T.C && space complexity of O(n) where n and m nums1.size() and nums2.size()
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums1.size(); i++) umap[nums1[i]] = i;
        for(int i = 0; i < (int)nums2.size(); i++) {
            if(umap.find(nums2[i]) == umap.end()) continue;
            for(int j = i + 1; j < (int)nums2.size(); j++) {
                if(nums2[i] < nums2[j]) {
                    ans[umap[nums2[i]]] = nums2[j];
                    break;
                }
            }
        }
        
        return ans;
    }
};
*/


/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force!! O(n*m) -> T.C && space complexity of O(m) where n and m nums1.size() and nums2.size()
        vector<int> ans(nums1.size(), -1);
        unordered_map<int, int> umap;
        
        for(int i = 0; i < (int)nums2.size(); i++) umap[nums2[i]] = i; // {value, index} map!!
        for(int i = 0; i < (int)nums1.size(); i++) {
            int pos = umap[nums1[i]];
            pos += 1; // we don't need to check itself!!
            while(pos < (int)nums2.size()) {
                if(nums1[i] < nums2[pos]) {
                    ans[i] = nums2[pos];
                    break;
                }
                pos++;
            }
            
        }
        
        return ans;
    }
};
*/