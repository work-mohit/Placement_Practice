bool helper(BinaryTreeNode<int> *root, int leftMin, int rightMax){
    if(root== NULL)
        return true;
    // check node
    if(root->data >= leftMin && root->data <= rightMax){
        return helper(root->left, leftMin, root->data) &&
				helper(root->right, root->data, rightMax);
    }else{
        return false;
    }
        
    
    
}
bool validateBST(BinaryTreeNode<int> *root) {
    return helper(root, INT_MIN, INT_MAX);
}