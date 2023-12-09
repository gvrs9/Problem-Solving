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
    vector<string> binaryTreePathsInString;
    string path = "";
    void binaryTreePathString(TreeNode* root) {

        path += to_string(root -> val);

        if(!root -> left && !root -> right) {
            binaryTreePathsInString.push_back(path);
            return;
        }

        if(root -> left) {
            path += "->";
            binaryTreePathString(root -> left);
            // cout << path << "\n";
            while(path.back() != '>') path.pop_back();
            path.pop_back();path.pop_back();
        }

        if(root -> right) {
            path += "->";
            binaryTreePathString(root -> right);
            // cout << path << "\n";
            while(path.back() != '>') path.pop_back();
            path.pop_back();path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        binaryTreePathString(root);
        return binaryTreePathsInString;
    }
};