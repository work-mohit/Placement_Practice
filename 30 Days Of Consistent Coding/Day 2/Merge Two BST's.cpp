// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1#
/*
    In the real world, sharing nodes between the old trees and the new tree can be a problem.
    If any of the old trees is deleted, it's going to also destruct the shared nodes in the new tree.
    C++ does have some nice & clean solutions for this, like using shared_ptr for example. 
    But as-is I'd say the 'trick' of reusing nodes from the old trees does more harm than good and if I were the interviewer,
    unless the interviewee points these nuances out I'd be lead to believe that they don't have a good grasp on memory management in C++. 
    Especially since the 'safe' solution is not that much more code:
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void solve(Node* root, vector<int> &v){
        if(root == NULL)
            return;
        solve(root->left, v);
        v.push_back(root->data);
        solve(root->right , v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> res;
       solve(root1,res);
       solve(root2, res);
       sort(res.begin(), res.end());
       return res;
       
    }
};

//////////////////////////////////////////////
// safe solution 

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return nullptr;
        int val1 = t1? t1->val:0;
        int val2 = t2? t2->val:0;
        
        TreeNode* t = new TreeNode(val1+val2);
        t->left = mergeTrees(t1?t1->left:nullptr,t2?t2->left:nullptr);
        t->right = mergeTrees(t1?t1->right:nullptr,t2?t2->right:nullptr);
        return t;
    }
};