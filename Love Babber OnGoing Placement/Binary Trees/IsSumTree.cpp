class Solution
{   
    private:
    pair<bool,int> helper(Node* root){
        if(root == NULL)
            return {true, 0};
        if(root->left == NULL && root -> right == NULL)
            return {true, root->data};
        
        pair<bool,int> leftans = helper(root->left);
        pair<bool,int> rightans = helper(root->right);    
        
        bool left = leftans.first;
        bool right = rightans.first;
        
        bool cond = (leftans.second + rightans.second) == root->data;
        
        int ans = root->data * 2;
        
        if(left && right && cond)
            return {true, ans};
        return {false,ans};
        
    }
    public:
    bool isSumTree(Node* root)
    {
        return helper(root).first;
        
    }
};