// https://leetcode.com/problems/merge-two-binary-trees/

class Solution {
public:
    TreeNode* solve(TreeNode* root1, TreeNode* root2){
       if(root1 && root2){
           root1->val += root2->val;
           root1->left = solve(root1->left, root2->left);
           root1->right = solve(root1->right, root2->right);
       }
        else{
            return (root1)?root1:root2;
        }
        return root1;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return solve(root1, root2);
    }
};