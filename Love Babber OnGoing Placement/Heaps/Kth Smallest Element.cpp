class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        for(int i =0; i < k ; i++){
            pq.push(arr[i]);
        }
        for(int i = k; i <= r;i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};
////////////////
// O(N*logN)
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr, arr + r + 1);
        return arr[k-1];
    }
};


//////
// quick select method avg O(n) TC

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    int partition(int a[], int left, int right, int pIndex)
    {
        // pick `pIndex` as a pivot from the array
        int pivot = a[pIndex];
     
        // Move pivot to end
        swap(a[pIndex], a[right]);
     
        // elements less than the pivot will be pushed to the left of `pIndex`;
        // elements more than the pivot will be pushed to the right of `pIndex`;
        // equal elements can go either way
        pIndex = left;
     
        // each time we find an element less than or equal to the pivot, `pIndex`
        // is incremented, and that element would be placed before the pivot.
        for (int i = left; i < right; i++)
        {
            if (a[i] <= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
     
        // move pivot to its final place
        swap(a[pIndex], a[right]);
     
        // return `pIndex` (index of the pivot element)
        return pIndex;
    }
    int quickselect(int nums[], int left, int right, int k)
    {
        // If the array contains only one element, return that element
        if (left == right) {
            return nums[left];
        }
     
        // select `pIndex` between left and right
        int pIndex = left + rand() % (right - left + 1);
     
        pIndex = partition(nums, left, right, pIndex);
     
        // The pivot is in its final sorted position
        if (k == pIndex) {
            return nums[k];
        }
     
        // if `k` is less than the pivot index
        else if (k < pIndex) {
            return quickselect(nums, left, pIndex - 1, k);
        }
     
        // if `k` is more than the pivot index
        else {
            return quickselect(nums, pIndex + 1, right, k);
        }
    }
    int kthSmallest(int arr[], int left, int right, int k) {
        return quickselect(arr, left, right, k-1);
    }
    
    
};

///////////////////
// using method called nth element 
int main()
{
    vector<int> a = { 7, 4, 6, 3, 9, 1 };
    const size_t k = 2;
 
    nth_element(a.begin(), a.begin() + k, a.end());
    cout << "k'th smallest element is " << a[k];
 
    return 0;
}