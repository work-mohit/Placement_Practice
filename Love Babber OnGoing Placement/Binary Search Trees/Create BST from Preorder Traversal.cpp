BinaryTreeNode<int>* preToBST(vector<int> &pre, int leftmin,int rightmax, int &i){
    if(i >= pre.size()){
        return NULL;
    }
   	if(pre[i] < leftmin || pre[i] > rightmax)
        return NULL;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[i++]);
    root->left = preToBST( pre, leftmin, root->data, i);
    root->right = preToBST(pre, root->data, rightmax, i);
    
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &pre) {
    int leftmin = INT_MIN;
    int rightmax = INT_MAX;
    int i = 0;
    
    return preToBST(pre, leftmin,rightmax, i);
}