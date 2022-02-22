// O(N^2)
class Solution{
    private:
    int height(Node* root){
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh) + 1;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(root == NULL)
            return true;
            
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        

        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left && right && diff)
            return 1;
        else
            return false;
        
    }
};

// O(N)
class Solution{
    private:
    pair<bool, int> helper(Node* root){
        if(root == NULL)
            return {true,0};
        
        pair<bool,int> ans;
        pair<bool,int> left = helper(root->left);
        pair<bool, int>  right = helper(root->right);
        
        bool exp = abs(left.second - right.second) <= 1;
        ans.first = false;
        ans.second = max(left.second , right.second) + 1;
        
        if(left.first && right.first && exp)
            ans.first = true;
        return ans;
       
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return helper(root).first;
        
    }
};