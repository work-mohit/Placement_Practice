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

//////

void makeMapping(vector<int> &in , int n, map<int, int> &m){
	 for(int i = 0 ; i < n; i++){
            m[in[i]] = i;
        }
    }
BinaryTreeNode<int>* BSTFromInAndPre(vector<int> in, vector<int> &pre,int n, int s, int e, int &idx,map<int, int> &m){
    if(idx >= n || s > e)
        return NULL;
    int ele = pre[idx++];   // get front element
        
    int pos = m[ele];   // find position
    
   
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(ele);
    root->left = BSTFromInAndPre(in, pre,n, s , pos-1, idx,m);
    root->right = BSTFromInAndPre(in ,pre ,n, pos+1, e, idx,m);
    
    return root;
    
}
BinaryTreeNode<int>* preorderToBST(vector<int> &pre) {
    
    vector<int> in = pre;
    int n = in.size();
    int idx = 0;
   	sort(in.begin(),in.end());
    
    map<int,int> m;
    makeMapping(in , n , m);
    
    return BSTFromInAndPre(in, pre,n, 0, n-1, idx,m);
    
}