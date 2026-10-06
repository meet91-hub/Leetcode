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
    unordered_map<int, int> postIndex;  
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    for (int i = 0; i < postorder.size(); i++) {
     postIndex[postorder[i]] = i;
    }
     return build(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,
       int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;
        int leftVal = preorder[preStart + 1];
        int leftPostIdx = postIndex[leftVal];
        int leftSize = leftPostIdx - postStart + 1;
        root->left = build(preorder, postorder, 
         preStart + 1, preStart + leftSize,
          postStart, leftPostIdx);
        root->right = build(preorder, postorder,
         preStart + leftSize + 1, preEnd,
         leftPostIdx + 1, postEnd - 1);
        return root;
    }
};