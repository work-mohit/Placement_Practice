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
void buildFromleverOrderTraversal(Node* &root){ 
    queue<Node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp -> left = new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp -> right = new Node(rightdata);
            q.push(temp->right);
        }
    }
    
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
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
int main(){
    Node* root = NULL;
    buildFromleverOrderTraversal(root);
    leverOrderTraversal(root);
    return 0;
}
