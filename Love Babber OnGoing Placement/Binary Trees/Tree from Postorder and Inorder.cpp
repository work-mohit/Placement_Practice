void makeMapping(int in[] , int n, map<int, int> &m){
        for(int i = 0 ; i < n; i++){
            m[in[i]] = i;
        }
    }
    Node* solve(int in[],int post[], int n, int &index, int inorderStart, int inorderEnd, map<int,int> &m){
        if(index < 0 || inorderStart > inorderEnd)
            return NULL;
        
        int ele = post[index--];  // ye imp hai
        Node* root = new Node(ele); 
        
        if(inorderStart == inorderEnd)
            return root; 
            
        int pos = m[ele];
        // phle right wala part then left wala part kyuki last se aare hai aur postorder me LRN , 
        // toh piche se aate waqt node ke barr Right aata
        root->right = solve(in, post, n ,index , pos+1, inorderEnd, m);
        root->left = solve(in, post, n,index, inorderStart, pos-1, m);
        
      
        return root;
    }
    Node* buildTree(int in[],int post[], int n)
    {
        int postIndex = n-1; //post order me last me aata hai node , means post order ka last ka element hamara root element hoga
        map<int,int> m;
        makeMapping(in, n , m);  // phle ye krlo , mza hi aa jaaega 
        return solve(in, post , n, postIndex ,0,n-1,m);  
    }