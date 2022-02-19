/*
https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     Sum of all min & max = 6 + 4 + 4 + 4 
                          = 18  
*/

long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	deque<int> S, G;
    long long sum = 0;
    
    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
    
    // now we greatest and smallest element in their respective queue
    
    for( ; i< n; i++){
        sum += arr[S.front()] + arr[G.front()];
        // now remove all previous greater element that are now out of index
        while(!S.empty() && S.front() <= i-k){
            S.pop_front();
        }
        while(!G.empty() && G.front() <= i-k){
            G.pop_front();
        }
        // now do same as we did for the first k elements
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
        
        G.push_back(i);
        S.push_back(i);
      
    }
    sum += arr[S.front()] + arr[G.front()];
    return sum ;
}
