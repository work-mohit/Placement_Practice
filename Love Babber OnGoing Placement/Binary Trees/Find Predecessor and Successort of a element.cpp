Node* predecessor(Node* root){
    Node* temp = root->left;
    while(temp->right != NULL){
        temp = temp -> right;
    }
    return temp;
}

Node* successor(Node* root){
    Node* temp = root->right;
    while(temp ->left != NULL){
        temp = temp -> left;
    }
    return temp;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL)
        return;
        
    if(root->key == key){
        if(root->left)
            pre = predecessor(root);
        if(root->right)
            suc = successor(root);
        return;
    }
    else if(root->key > key){
        suc = root;        // kya pta root hi toh save krlo 
        findPreSuc(root->left , pre, suc , key);
    }else{
        pre = root;             // kya pta root hi ho toh sae krlo 
        findPreSuc(root->right, pre, suc, key);
    }
    
    return;
}