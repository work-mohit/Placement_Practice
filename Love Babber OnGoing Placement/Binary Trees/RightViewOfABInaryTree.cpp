class Solution
{
    public:
    void helper(Node* root, vector<int> &ans, int lvl){
        if(root == NULL)
            return ;
        if(lvl == ans.size())
            ans.push_back(root->data);
        helper(root->right,ans, lvl+1);
        helper(root->left,ans, lvl+1);
        
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
        
        helper(root,ans, 0);
        return ans;
    }
    
    
   
};