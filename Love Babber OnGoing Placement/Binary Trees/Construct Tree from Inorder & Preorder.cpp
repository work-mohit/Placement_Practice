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
        return solve(in, pre , n, preIndex ,0 , n);
    }
};