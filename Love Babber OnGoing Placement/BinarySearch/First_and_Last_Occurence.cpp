// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?leftPanelTab=0

int firstOcc(vector<int>& arr,int n, int k){
	int s = 0;
    int e = n -1;
    int mid = s + (e - s)/2;
    int ans = -1;
   	while(s <= e){
		if(arr[mid] == k){                   //           |
            ans = mid;                       //           |  Main Part if we found our element in the mid then for first occurence
            e = mid - 1;                     //           |  we have to move left side 
        }else if(arr[mid] > k){
            e = mid-1;
        }else{
            s = mid+1;
        }  
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOcc(vector<int>& arr,int n, int k){
	int s = 0;
    int e = n -1;
    int mid = s + (e - s)/2;
    int ans = -1;
   	while(s <= e){
		if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }else if(arr[mid] > k){
            e = mid-1;
        }else{
            s = mid+1;
        }  
        mid = s + (e-s)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> pans;
    pans.first = firstOcc(arr,n,k);
    pans.second = lastOcc(arr,n,k);
    return pans;
}