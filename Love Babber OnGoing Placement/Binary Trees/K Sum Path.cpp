// https://leetcode.com/problems/path-sum-iii/
// https://practice.geeksforgeeks.org/problems/k-sum-paths/
class Solution{
  public:
    void solve(Node* root, int k, vector<int> path , int &count){
        if(root == NULL)
            return;
        
        path.push_back(root->data);
        
        solve(root->left, k , path, count);
        solve(root->right, k , path , count);
        int sum = 0;
        for(int i = path.size()-1;i >= 0; i--){
            sum += path[i];
            if(sum == k)
                count++;
        }
        path.pop_back();
        
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root , k , path, count);
        return count;
    }
};
// In leetcode it is as named as Path Sum III
class Solution{
  public:
    int count;
    int target;
    unordered_map<long ,int> umap;
    void solve(Node* root, int sum){
        if(root == NULL)
            return;
            
        sum += root->data;
        int prefixSum = sum - target;
        if(umap.count(prefixSum)){     // if exists then only increment 
            count += umap[prefixSum];
        }
        umap[sum]++;
        solve(root->left, sum);
        solve(root->right, sum);
        umap[sum]--;
        
    }
    int sumK(Node *root,int k)
    {
        count = 0;
        target = k;
        umap[0] = 1;
        solve(root ,0);
        return count;
    }
};
