#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }    
};

Node* insertInToBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        root->right = insertInToBST(root->right,d);
    }  
    else{
        root->left = insertInToBST(root->left, d);
    } 
    return root;
}

void takeInput(Node* &root){
    int d;
    cin>>d;

    while(d != -1){
        root = insertInToBST(root, d);
        cin>>d;
    }
}
void inorderTraversal(Node* root){
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp -> left;
    }
    return root;
}
Node* deleteFromBST(Node* root, int x){
    // base case 
    if(root == NULL)
        return root;

    if(root->data == x){
        // 0 child
        if(root->left == NULL  && root->right == NULL){
            delete root;
            return NULL;
        }
         // 1 left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // 1 right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right != NULL)
            Node* mini = minVal(root->right);  // get min value form the right subtree.
            root->data = mini->data;
            root->right = deleteFromBST(root->right, mini);
            // return root;
        }
    }
    else if(root->data > x){
        root->left = deleteFromBST(root->left , x);    
    }
    else{
        root->right = deleteFromBST(root->right, x);
        
    }
    return root;
}

int main(){
    Node* root = NULL;
    takeInput(root);
    inorderTraversal(root);
    cout<<endl;
    cout<<"Delete node:\n";
    deleteFromBST(root,25);
    cout<<minVal;
    return 0;
}