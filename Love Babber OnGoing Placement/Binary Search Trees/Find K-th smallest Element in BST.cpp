int helper(BinaryTreeNode<int>* root, int k, int &i){
    if(root == NULL)
        return -1;
    int left = helper(root->left , k , i);
    
    if(left != -1)
        return left;
    
    i++;
    if(i == k)
        return root->data;
    
    return helper(root->right, k , i);
    
    
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int  i = 0;
    return helper(root, k , i);
    
}