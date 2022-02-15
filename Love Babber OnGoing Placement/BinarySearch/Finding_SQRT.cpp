//https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0
long long int SearchTheSQRT(long long int N){
    long long int s = 0;
    long long int e = N;
    long long int mid = s + (e -s)/2;
    long long ans = -1;
    while(s <= e){
        unsigned long long int square = mid * mid;
        if(square == N){
            return mid;
        }
        if(square < N){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid -1;
        }
        mid = s + (e -s)/2;
    }
    return ans;
}
int sqrtN(long long int N)
{
    return SearchTheSQRT(N);
}


//////////////////////////////////////////////////////////////////////////////////////////////
// LeetCode Solution
//https://leetcode.com/problems/sqrtx/
class Solution {
private:
    long long int SearchTheSQRT(int N){
        int s = 0;
        int e = N >> 1;// divide by 2;
        if (N==1) return N;
        long long int mid = s + (e -s)/2;
        int ans = -1;
        while(s <= e){
            long long int square = mid * mid;
            if(square == N){
                return mid;
            }
            if(square < N){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid -1;
            }
            mid = s + (e -s)/2;
        }
        return ans;
    }
public:
    int mySqrt(int x) {
        return SearchTheSQRT(x);
    }
};