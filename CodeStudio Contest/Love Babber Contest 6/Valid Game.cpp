int solve(TreeNode<int>* root, int leftMin , int rightMax){
    if(root == NULL)
        return 1;
    
    bool left = solve(root->left , leftMin, root->data);
    bool right = solve(root->right, root->data, rightMax);
    
    bool flag = true;
    
    
    flag = root->data > leftMin && root->data < rightMax;
    
    if(left && right && flag)
        return 1;
    
    return 0;
}

int validGame(TreeNode < int > * root) {
   return solve(root, INT_MIN, INT_MAX);
}