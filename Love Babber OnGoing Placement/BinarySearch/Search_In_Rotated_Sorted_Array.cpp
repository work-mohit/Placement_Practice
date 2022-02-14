int getPivot(vector<int>& arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }else 
            e = mid;
        mid = s + (e-s)/2;
    }
    return s;
}
int binarySearch(vector<int>& arr,int s, int e , int k){
    int mid = s + (e-s)/2;
    
    while(s <= e){
        if(arr[mid] == k)
        	return mid;
    	if(k >arr[mid]){
        	s = mid + 1;
    	}else{
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    return -1;
}
int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    int idx = -1;
   	if(k >= arr[pivot] && k <= arr[n-1])
        return binarySearch(arr, pivot, n-1, k);
    else{
        return binarySearch(arr, 0, pivot, k);
    }
   
}

