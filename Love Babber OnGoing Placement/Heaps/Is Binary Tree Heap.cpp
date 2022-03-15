class Solution {
  public:
    bool isCBT(struct Node* root,int i , int countNodes){
        if(root == NULL)
            return true;
        
        if(i >= countNodes)
            return false;
        else{
            bool left = isCBT(root->left, 2*i+1, countNodes);
            bool right = isCBT(root->right, 2*i + 2, countNodes);
            return left && right;
        }
        
    }
    bool kyaMaxHeapHai(struct Node* root){
        // leaf node 
        if(root->left == NULL || root->right == NULL)
            return true;
        // if right ==
        
        if(root->right == NULL)    
            return root->data > root->left->data;
       
        bool cond = (root->data >= root->left->data && root->data >= root->right->data);
        
        
        return kyaMaxHeapHai(root->left) && kyaMaxHeapHai(root->right) && cond;
    }
    
    int countNodes(struct Node* root){
        if(root == NULL)
            return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right);    
        
    }
    bool isHeap(struct Node* root) {
        int cnt = countNodes(root);
        int i = 0;
        if(isCBT(root, i, cnt) && kyaMaxHeapHai(root))
            return true;
        return false;
    }
};