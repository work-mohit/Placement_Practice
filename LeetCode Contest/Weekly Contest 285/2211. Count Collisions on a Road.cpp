class Solution {
    public int countCollisions(String directions) {
        int left = 0;
        int right = directions.length() - 1;
        int cnt = 0;

        // left side me phle jitne bhi left ko jari unhe hta do 
        // unka koi contribution nhi 
        while(left <= right && directions[left] == 'L'){
            left++;
        }

        // same right side se jo R ko jaari phle .. un sb ko hta do 
        while(right >= 0 && directions[right] == 'R'){
            right--;
        }
        
        // ab jo bache kuche bache usme stationary car ho ya na ho baat brabar hi hai 
        // toh bs count krlo kitne left and right hai total 
        for(int i = left; i<=right; i++){
            if(directions[i] != 'S'){
                cnt++;
            }
        }
        return cnt;
    }
}

//