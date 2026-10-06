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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;
        for (int i = 0; i < inorder.size(); ++i) pos[inorder[i]] = i;
        int preIdx = 0;
        return build(preorder, pos, preIdx, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& pos,
                    int& preIdx, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = pos[rootVal];
        root->left = build(preorder, pos, preIdx, inLeft, mid - 1);
        root->right = build(preorder, pos, preIdx, mid + 1, inRight);
        return root;
    }
};