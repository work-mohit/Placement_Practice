// approach 1 

void inorder_convert(TreeNode<int>* curr, TreeNode<int>* &prev)
{
    if (curr == NULL)
        return;
    inorder_convert(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder_convert(curr->right, prev);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* dummy = new TreeNode<int>(-1);
    dummy->right = NULL;
    dummy -> left = NULL;
  
    TreeNode<int>* prev = dummy;
  
    inorder_convert(root, prev);
  
    prev->left = NULL;
    prev->right = NULL;

    return dummy->right;
}
// approach 2

void inorder(TreeNode<int>* &root, vector<TreeNode<int>*> &in){
    if(root== NULL)
        return;
    inorder(root->left,in);
    in.push_back(root);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // make vector by doing inorder traversal 
    vector<TreeNode<int>* > in;
    inorder(root, in);
    if(in.size() <= 1)
        return root;
    int n = in.size()-1;
    
    // now change the every node;
    TreeNode<int>* temp = in[0];
    for(int i = 0; i < n;i++){
        in[i]->left = NULL;
        in[i]->right = in[i+1];
    }
    in[n]->left = NULL;
    in[n]->right = NULL;
    
   	return temp;
    
}

// approach 3 which same as approach 2
// code that in video , and only accepted code in codestudio

void inorder(TreeNode<int>* &root, vector<int> &in){
    if(root== NULL)
        return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // make vector by doing inorder traversal 
    vector<int> in;
    inorder(root, in);
    if(in.size() <= 1)
        return root;
    int n = in.size();
   
    // now change the every node;
    TreeNode<int>* newRoot = new TreeNode<int>(in[0]);
    TreeNode<int>* curr = newRoot;
    for(int i = 1; i < n;i++){
       TreeNode<int>* temp = new TreeNode<int>(in[i]);
       curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    
   	return newRoot;
    
}
