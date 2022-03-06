
// Morris Traversal

class Solution
{
    public:
    
    void flatten(Node *root)
    {
        if(root == NULL || root->left == NULL && root->right == NULL)
            return;
            
        Node* curr = root;
        Node* temp;
        while(curr != NULL){
            if(curr->left != NULL){
                temp = curr->left;
                while(temp ->right != NULL){
                    temp = temp->right;
                }
                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                
            }
            curr =curr->right;
        }
        

    }
};

// Using recursion 

class Solution
{
    public:
    
    void flatten(Node *root)
    {
        
        if (root == NULL || root->left == NULL &&
                            root->right == NULL) {
            return;
        }
     
        
        if (root->left != NULL) {
     
            // move left recursively
            flatten(root->left);
        
            // store the node root->right
            Node* tempRight = root->right;
            root->right = root->left;
            root->left = NULL;
     
            // find the position to insert
            // the stored value  
            Node* temp = root->right;
            while (temp->right != NULL) {
                temp = temp->right;
            }
     
            // insert the stored value
            temp->right = tempRight;
        }
     
        flatten(root->right);
        

    }
};