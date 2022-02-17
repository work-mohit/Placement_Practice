// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    int arr[26];
		    for(int i =0; i < 26; i++)
		        arr[i] = 0;
		        
		    for(int i =0 ; i < A.length(); i++){
		        arr[A[i]-'a']++;
		        q.push(A[i]);
		        while(!q.empty()){
		            if(arr[q.front()-'a'] > 1 )  // repeating character
		                q.pop();
                    else{
                        A[i] = q.front();
                        break;
                    }     
		        }
		        if(q.empty())
		            A[i] = '#';
		    }
		    return A;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends