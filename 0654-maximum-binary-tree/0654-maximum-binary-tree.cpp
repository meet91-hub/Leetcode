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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) return nullptr;
     int maxIdx = 0;
      for (int i = 1; i < nums.size(); i++) {
     if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
   TreeNode* root = new TreeNode(nums[maxIdx]);
  vector<int> left(nums.begin(), nums.begin() + maxIdx);
    vector<int> right(nums.begin() + maxIdx + 1, nums.end());
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right); 
    return root;
    }
};