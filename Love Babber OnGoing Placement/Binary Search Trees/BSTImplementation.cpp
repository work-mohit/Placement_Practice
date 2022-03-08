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

int main(){
    Node* root = NULL;
    takeInput(root);
    inorderTraversal(root);
    return 0;
}