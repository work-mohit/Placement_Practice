//O(N^2)
class Solution {
private:
    int height(Node* node){
        if(node == NULL){
            return 0;
        }
        int lh = height(node->left);
        int rh = height(node->right);
        
        return 1 + max(lh,rh);
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int ans = 0;
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
            
        int lh = height(root->left);
        int rh = height(root->right);
        
        int currd= lh + rh + 1;
        
        ans = max(ans , currd);
    }
};

// O(N)
class Solution {
private:
    pair<int,int> diameterFast(Node* root){
        if(root == NULL){
            return {0,0};
        }
        // (diameter, height)
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = 1 + left.second + right.second;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2,op3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

// another approach with O(N)
class Solution {
public:
    
    int ans=0;
    
    int height(Node *root){
        
        if(root==NULL) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        ans =max(ans, 1+lh+rh);
        
        return 1+max(lh,rh);
    }
    
    
    int diameter(Node* root) {
        height(root);
        return ans;
    }
};