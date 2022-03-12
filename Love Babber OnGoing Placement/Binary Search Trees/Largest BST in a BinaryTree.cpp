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
