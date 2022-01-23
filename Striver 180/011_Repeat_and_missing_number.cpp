// https://www.codingninjas.com/codestudio/problems/873366
// Given and N size array which has 1 to N + 1 numbers , and their is one no is being repeated 
// so obviously 1 number will be missing 
// we have to return both number < missing number, repeated number>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int, int > ans;
    int i = 0;
    int temp = 0;
        while(i < n){               //    index       0 1 2 3 4 5    for i = 0
            temp = arr[i]-1;         //    nums       1 4 6 3 5 4        temp = arr[0]-i => 0
            if(arr[i] != arr[temp]){    //                              arr[0] != arr[temp]=> arr[0] != arr[0] false i++
                swap(arr[i],arr[temp]); //              
            }
        else
            i++;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != i+1){
            ans.first = i+1;
            ans.second = arr[i];
        }
            
    }

        return ans;
}
