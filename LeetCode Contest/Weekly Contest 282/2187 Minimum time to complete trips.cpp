class Solution {
private:
    long long giveMeTime(vector<int>& time, long long t){
        long long cnt = 0;
        
        for(int x: time){
            
            cnt += t / (1LL*x);     
        } 
      
        return cnt;
    }
public:
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long  s = 0;
        long long e = 1e14;
        long long mid;
        while(s < e){
            mid = s + (e - s)/2;
            if(giveMeTime(time,mid) >= totalTrips){
                e = mid;
            }else{
                s = mid + 1;
            }
        }
        return s;      
    }
};