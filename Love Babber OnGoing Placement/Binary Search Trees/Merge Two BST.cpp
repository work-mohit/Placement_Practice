// T.C = O(M+N), S.C = O(M+N)

void inorderTraversal(TreeNode<int>* &root,vector<int> &in){
    if(root == NULL)
        return;
    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right,in);
}
vector<int> mergeTwoSortedArray(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    vector<int> arr(n+m);
    int i = 0;
    int j = 0;
    int k = 0;
   	
    while(i <n && j < m){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }
    }
   	while(i  < n){
        arr[k++] = a[i++];
    }
    while(j < m){
        arr[k++] = b[j++];
    }
    return arr;
}
TreeNode<int>* makeBSTFromASortedArray(vector<int> &arr, int s , int e){
    if(s > e)
        return NULL;
    int mid= (s + e)/2;
    
	
    TreeNode<int>* root= new TreeNode<int>(arr[mid]);
    
    root->left = makeBSTFromASortedArray(arr, s, mid-1);
    root->right = makeBSTFromASortedArray(arr, mid+1 , e);
    return root;
    
}
TreeNode<int>* mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // find indorder of the bst's
    vector<int> arr1, arr2;
   	inorderTraversal(root1, arr1);
    inorderTraversal(root2, arr2);
    
    // merge 2 sorted arrays
    vector<int> arr = mergeTwoSortedArray(arr1, arr2);
    
    
    // make bst of a sorted array 
    return makeBSTFromASortedArray(arr, 0 , arr.size()-1);
}


////////////////////////////////////////////////////////////////////////////