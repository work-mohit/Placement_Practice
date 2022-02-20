// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

/*
O(NK) 
Normal approach : run a outer loop from i to n-k+1
                        run a inner loop for each window size a find negative element 
O(N) O(N)
better approach :
        make a deque
        first run a loop till k and if found any negative then put index in the deque
        then check if dq is empty or not .. for every window ans will be queue front 
        and we also discard index from queue if we have out of range index.

O(N) O(1)
Optimized Approach:: It is also possible to accomplish this with constant space. 
The idea is to have a variable firstNegativeIndex to keep track of the first negative 
element in the k sized window. At every iteration, we skip the elements which no longer
 fall under the current k size window (firstNegativeIndex <= i – k) as well as the positive elements
*/

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long int> ans;
    
    queue<long long int> dq;
    
    
    for(int i =0; i< K;i++){
        if(A[i]< 0)
            dq.push(i);     // we store index in deque
    }
    if(dq.empty())
        ans.push(0);
    else
        ans.push(A[dq.front()]);
        
    for(int i = K; i < N; i++){
        if(!dq.empty() && i - dq.front() >= K)        // this is the condition that dq have index 
              dq.pop();                           // that is currenly not it our range
        
       
        if(A[i]< 0)
            dq.push(i);     // we store index in deque
        
        if(dq.empty())
            ans.push(0);
        else
            ans.push(A[dq.front()]);
        
    } 
    
    return ans;
 }