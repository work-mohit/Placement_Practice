class Solution
{
    public:
        bool check(int p , int n){
            int temp = p, count = 0, f = 5;
            while(f <= temp){
                count += temp / f;
                f = f * 5;
            }
            return count >= n;
        }
        int findNum(int n)
        {
            if(n==1)
                return 5;
                
            int low = 0, high = 5*n;
            
            while(low < high){
                int mid = (low+ high) >> 1;
                if(check(mid , n))
                    high = mid;
                else
                    low = mid + 1;
            }
            return low;
        }
};