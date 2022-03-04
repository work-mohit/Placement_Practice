// using getsumUtil and sumOfGrandChildren
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int sumOfGrandChildren(Node* root, map<struct Node*,int> &mp){
        int sum = 0;
        if(root->left)
            sum += getMaxSumUtil(root->left->left, mp) + getMaxSumUtil(root->left->right, mp);
        if(root->right)
            sum += getMaxSumUtil(root->right->left, mp) + getMaxSumUtil(root->right->right, mp);
        
        return sum;    
        
    }
    int getMaxSumUtil(Node* root, map<struct Node*,int> &mp){
        if(root == NULL)
            return 0;
            
        if(mp.find(root) != mp.end())
            return mp[root];

        // you include root node    
        int incl = root->data + sumOfGrandChildren(root, mp);
        // you exclude root node
        int excl = getMaxSumUtil(root->left, mp) + getMaxSumUtil(root->right, mp);
        
        mp[root] = max(incl, excl);
        
        return mp[root];
    }
    int getMaxSum(Node *root) 
    {
        if(root == NULL)
            return 0;
        map<struct Node*, int> mp;
        return getMaxSumUtil(root, mp);
    }
};

// using pair

pair<int, int> maxSumHelper(Node *root)
{
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    // < sum including this node, sum excluding this node >
    pair<int, int> left = maxSumHelper(root->left);
    pair<int, int> right = maxSumHelper(root->right);
    pair<int, int> sum;
 
    root-> data + excludeing right + excluding left
    sum.first = root->data + right.second + left.second;
 
    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(right.first, right.second) +
                 max(left.first, left.second);
 
    return sum;
}
 
int maxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}