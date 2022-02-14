class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s =0;
        int e = n-1;
        int mid= s + (e-s)/2;
        
        while(s < e){
            if(arr[mid] < arr[mid+1]){
            s = mid + 1;
            }else{
                e = mid;
            }
            mid= s + (e-s)/2;
        }
        return mid;
    }
};
//////////////////////////////////////////////////////


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        
        int middle;
        int peak_index;
        
        while(start <= end)
        {
            middle  = (start + end)/2;
            
            // Comparing with the next element
            if(arr[middle] > arr[middle + 1])
            {
                peak_index = middle;
                end = middle - 1;
            }
            
            else if(arr[middle] < arr[middle + 1])
                start = middle + 1;
            
            // Comparing with the previous element
            else if(arr[middle] > arr[middle - 1])
            {
                peak_index = middle;
                start = middle + 1;
            }
            
            else if (arr[middle] < arr[middle -1])
                end = middle - 1;
        }
        return peak_index;
    }
};