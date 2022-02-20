// https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-10/problems/16774

long long totalBill(int n, vector<int>& a)
{
    long long mx = INT_MIN;
    long long sum = 0;
    for(auto x : a){
        sum += x;
        mx = mx > x?mx : x;
    }
    return sum-2*mx;  
}
