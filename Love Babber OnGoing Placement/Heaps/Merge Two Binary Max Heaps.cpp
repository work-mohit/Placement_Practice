class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
        
        if(largest != i){
            swap(arr[i] , arr[largest]);
            heapify(arr, n, largest);
        }
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // merge two arrays
        for(auto x : b)
            a.push_back(x);
        
        // build heap with array 
        int size = a.size();
        for(int i = size/2-1; i >= 0; i--)
            heapify(a, size , i);
        
        return a;
    }
};

////////////////////////////////////////////////////////////////

class Solution{
    public:
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       priority_queue<int> pq;
       for(auto x : a)
            pq.push(x);
        for(auto x : b)
            pq.push(x);
        vector<int> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
    
};