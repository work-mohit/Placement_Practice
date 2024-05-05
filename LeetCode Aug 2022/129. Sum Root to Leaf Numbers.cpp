// my submission

class Solution {
public:
    int gsum = 0;
    void dfs(TreeNode* root, int sum){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            sum += root->val;
            gsum += sum;
            return;
        }
        
        sum += root->val;
        
        dfs(root->left, sum*10);
        dfs(root->right, sum*10);
        
    }
    int sumNumbers(TreeNode* root) {
        
        dfs(root, 0);
        return gsum;
    }
};

// another one but clear approach
// dfs recursive
class Solution {
public:
    
    int dfs(TreeNode* root, int sum){
        if(!root)return NULL;
        
        sum = sum*10 + root->val;
        if(!root->left && !root->right)
            return sum;
    
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        
        return dfs(root, 0);
        
    }
};
// dfs preorder

class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        
        stack<pair<TreeNode*, int>> stk;
        
        stk.push({root, 0});
        int sum =0;
        while(!stk.empty()){
            auto [root, cur] = stk.top(); stk.pop();
            
            cur = cur*10 + root->val;
            if(!root->left && !root->right) sum+= cur;  // leaf node
            
            if(root->right)stk.push({root->right, cur});
            if(root->left) stk.push({root->left, cur});
        }
        return sum;
        
    }
};

