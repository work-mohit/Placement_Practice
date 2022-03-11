class Solution{
    public:
    int findPosition(int in[] , int n, int ele){
        for(int i = 0 ; i < n; i++){
            if(ele == in[i]){
                return i;
            }
        }
            
        return -1;        
    }
    Node* solve(int in[],int pre[], int n, int &index, int inorderStart, int inorderEnd){
        if(index >= n || inorderStart > inorderEnd)
            return NULL;
            
        int ele = pre[index++];
        Node* root = new Node(ele);
        
        int pos = findPosition(in,n,ele);
        
        
        root->left = solve(in, pre, n,index, inorderStart, pos-1);
        root->right = solve(in, pre, n ,index , pos +1, inorderEnd);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        return solve(in, pre , n, preIndex ,0 , n-1);
    }
};

///////// 
// with making maping of the positions 
// inorder and preorder

class Solution{
    public:
    void makeMapping(int in[] , int n, map<int, int> &m){
        for(int i = 0 ; i < n; i++){
            m[in[i]] = i;
        }
    }
    Node* solve(int in[],int pre[], int n, int &index, int inorderStart, int inorderEnd, map<int,int> &m){
        if(index >= n || inorderStart > inorderEnd)
            return NULL;
            
        int ele = pre[index++];
        Node* root = new Node(ele);
        
        int pos = m[ele];
        
        
        root->left = solve(in, pre, n,index, inorderStart, pos-1, m);
        root->right = solve(in, pre, n ,index , pos +1, inorderEnd, m);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        map<int,int> m;
        makeMapping(in, n , m);
        return solve(in, pre , n, preIndex ,0 , n-1,m);
    }
};


// inorder and postorder

void makeMapping(int in[] , int n, map<int, int> &m){
        for(int i = 0 ; i < n; i++){
            m[in[i]] = i;
        }
    }
Node* solve(int in[],int post[], int n, int &index, int inorderStart, int inorderEnd, map<int,int> &m){
    if(index < 0 || inorderStart > inorderEnd)
        return NULL;
    
    int ele = post[index--];
    Node* root = new Node(ele); 
    
    if(inorderStart == inorderEnd)
        return root; 
        
    int pos = m[ele];
    
    root->right = solve(in, post, n ,index , pos+1, inorderEnd, m);
    root->left = solve(in, post, n,index, inorderStart, pos-1, m);
    
    
    return root;
}
Node* buildTree(int in[],int post[], int n)
{
    int postIndex = n-1;
    map<int,int> m;
    makeMapping(in, n , m);
    return solve(in, post , n, postIndex ,0,n-1,m);
}