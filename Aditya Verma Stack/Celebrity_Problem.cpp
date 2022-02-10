//  TC: O(N)  SC: O(N)

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
       // push all
        for(int i = 0 ; i < n ; i++)
            s.push(i);
        // fine tune potential candidate
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(M[a][b] ==1)
                s.push(b);
            else
                s.push(a);
        }
        // This candidate is the potential candidate for the celerbrity 
        int candidate = s.top();
        
        // now check rows first 
        int rowcnt = 0;
        for(int i = 0; i < n ; i++){
            if(M[candidate][i] == 0)
                rowcnt++;
        }
        // now check column of the candidate
        int colcnt = 0;
        for(int i = 0; i < n ; i++){
            if(M[i][candidate] == 1)
                colcnt++;
        }
        // last check 
        if(rowcnt == n && colcnt == n-1)
            return candidate;
        else 
            return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
 
/////////////////////////////////////////////////////////////////////////////////
/// Two Pointers Approach 

// TC : O(N)  SC: O(1)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i = 0;
        int j = n-1;
        while(i < j){
            if(M[i][j] == 1)
                i++;
            else
                j--;
       }
       int candidate = i;
       
       for(i = 0; i< n; i++){
           if(i != candidate){
               if(M[i][candidate] == 0|| M[candidate][i])
                    return -1;
           }
       }
       return candidate;
    }
};

