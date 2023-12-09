/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void treeToString(TreeNode* root) {
        if(root == NULL) return;

        ans += to_string(root -> val);
        if(!root -> right && !root -> left) return;
        
        ans += "(";
        treeToString(root -> left);
        ans += ")";
        
        if(root -> right) {
            ans += "(";
            treeToString(root -> right);
            ans += ")";
        }
    }
public:
    string ans = "";
    string tree2str(TreeNode* root) {
        treeToString(root);
        return ans;
    }
};

/*
class Solution {
private:
    void treeToString(string& ans, TreeNode* root) {
        if(root == NULL) return;

        ans += to_string(root -> val);
        if(root -> right && !root -> left) ans += "()";
        
        if(root -> left) {
            ans += "(";
            treeToString(ans, root -> left);
            ans += ")";
        }
        
        if(root -> right) {
            ans += "(";
            treeToString(ans, root -> right);
            ans += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        treeToString(ans, root);
        return ans;
    }
};
*/