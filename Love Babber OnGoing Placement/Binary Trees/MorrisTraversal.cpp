vector<int> morrisPreTraversal(TreeNode* root) {
    if(root== NULL)
        return;
    TreeNode* curr = root;
    TreeNode* temp;
    vector<int> ans;
    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            temp = curr ->left;
            while(temp->right != NULL && temp->right != curr){
                temp= temp-> right;
            }
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr -> left;
            }else{
                temp->right = NULL;
                ans.push_back(curr->data);
                curr = curr -> right;
            }
        }
    }
    return ans;
}