int solve(TreeNode<int>* root, int leftMin , int rightMax){
    if(root == NULL)
        return 1;
    
    // first go deep down to the Tree
    bool left = solve(root->left , leftMin, root->data);
    bool right = solve(root->right, root->data, rightMax);
    
    // keep this initially true
    bool flag = true;
    
    // this will update here
    flag = root->data > leftMin && root->data < rightMax;
    // check all three condition to be a valid game.
    if(left && right && flag)
        return 1;
    
    return 0;
}

int validGame(TreeNode < int > * root) {
   return solve(root, INT_MIN, INT_MAX);
}