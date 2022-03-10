void inorder(TreeNode<int>* root,vector<int> &in){
    if(root== NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* inorderToBST(vector<int> &in , int s ,int e){
    if(s > e)
        return NULL;
    int mid = s + (e-s)/2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(in, s, mid-1);
    root->right = inorderToBST(in, mid+1, e);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
   	vector<int> in;
    inorder(root, in);
    return inorderToBST(in, 0 , in.size()-1);
}