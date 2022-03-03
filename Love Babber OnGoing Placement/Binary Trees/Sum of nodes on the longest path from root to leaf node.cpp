//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/
class Solution
{
private:
    void solve(Node* root, int sum , int &maxsum, int len, int &maxlen){
        if(root == NULL){
            if(len > maxlen){
                maxlen = len;
                maxsum = sum;
            }else if(len == maxlen){
                maxsum = max(sum ,maxsum);
            }
            return ;
        }
        solve(root->left , sum+root->data , maxsum, len+1, maxlen);
        solve(root->right , sum+root->data , maxsum, len+1, maxlen);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int sum = 0;
        int maxsum = INT_MIN;
        int len = 0;
        int maxlen = 0;
        solve(root , sum , maxsum, len, maxlen);
        return maxsum;
    }
};