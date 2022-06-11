class info{
    public:
    	int mini;
    	int maxi;
    	bool isBST;
    	int size;
};

info returnHeightOfLargestBST(TreeNode<int>* root, int &ans){
    if(root== NULL)
        return {INT_MAX, INT_MIN, true, 0};
   
    info left = returnHeightOfLargestBST(root->left,ans);
    info right = returnHeightOfLargestBST(root->right,ans);
    
    info currNode;
    
    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);
    currNode.size = left.size + right.size + 1;
    
    if(left.isBST && right.isBST && (left.maxi < root->data && root->data < right.mini))
    	currNode.isBST = true;
    else 
        currNode.isBST = false;
    
    if(currNode.isBST) 
    	ans = max(ans, currNode.size);
    
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
   	info temp = returnHeightOfLargestBST(root, maxSize);
    return maxSize;
}
////////////////////////////////////////////////////
// GFG soltion 

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int size(Node* root){
        if(root == NULL)
            return 0;
        return size(root->left)+ size(root->right) + 1;
    }
    bool isBST(Node *root ,int mini , int maxi){
        if(root == NULL)
            return true;
        
        bool isleft = isBST(root->left , mini , root->data);
        bool isright = isBST(root->right, root->data, maxi);
        
        if(mini >= root-> data || maxi <= root-> data) 
            return false;
       
        
        return isleft && isright;
    }
    int largestBst(Node *root)
    {
    	if(isBST(root, INT_MIN, INT_MAX))
    	    return size(root);
    	 else
    	    return max(largestBst(root->left) , largestBst(root->right));
    }
};