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
    unordered_map<int, int> mp;  
public:
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, 
    int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd) return NULL;
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
    int rootIndex = mp[rootVal];
     int leftSize = rootIndex - inStart;
    root->left = build(inorder, postorder, inStart, rootIndex-1, 
      postStart, postStart+leftSize-1);
     root->right = build(inorder, postorder, rootIndex+1, inEnd, 
     postStart+leftSize, postEnd-1);    
        return root;
    }
};