#include<iostream> 
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
            this->data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
        
};
Node* buildtree(Node* root){
    
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1)
        return NULL;

    cout<<"Enter the left element of "<<root->data<<endl;
    
    root -> left = buildtree(root->left);
    cout<<"Enter the right element of "<<root->data<<endl;
    root -> right = buildtree(root->right);
    return root;
}
void leverOrderTraversal(Node* root){
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    
}
void InOrder(Node* root){
    if(root== NULL)
        return;
    
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void preOrder(Node* root){
    if(root== NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root){
    if(root== NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
// 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1 -1 
int main(){
    Node* root = NULL;
    root = buildtree(root);
    cout<< "Lever Order Traversal :";
    leverOrderTraversal(root);
    
    cout<< "In-Order Traversal :"<<endl;
    InOrder(root);
    cout<<endl;
    cout<< "Pre-Order Traversal :"<<endl;
    preOrder(root);
    cout<<endl;
    cout<< "Post-Order Traversal :"<<endl;
    postOrder(root);
    return 0;
}