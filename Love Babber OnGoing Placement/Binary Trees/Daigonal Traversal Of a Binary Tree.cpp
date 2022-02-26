void helper(Node* root, unordered_map<int,vector<int> > &res, int lvl){
    if(root == NULL)
        return;
    
    res[lvl].push_back(root->data);
    helper(root->left, res, lvl+1);
    helper(root->right, res, lvl);
}

vector<int> diagonal(Node *root)
{
    unordered_map<int,vector<int> > res;
    vector<int> ans;
    if(root == NULL) 
        return ans;
    helper(root, res, 0);
    
    for (int i = 0; i < res.size(); i++)
    {
        for (int j: res[i]) {
            ans.push_back(j);
        }
        
    }
    return ans;
}