/* 
my first approach was to form the number from digits
and then add 1 and then break and push into res vector
reverse the vector and return it 

pr jyada hi brute force thi 

*/


// my approach (2nd approach)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        int dig = 0, carry = 0;
        while(n--){
            dig = digits[n] + carry;
            if(n == digits.size() -1)
                dig++;
            carry = dig / 10;
            res.push_back(dig % 10);
        }
        if(carry != 0)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};


// consise and beautiful approach
void plusone(vector<int> &digits)
{
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			return;
		}
	}
		digits[0] =1;
		digits.push_back(0);
		
}

// with comments

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size() - 1;
      
      for (int i = n; i >= 0; --i) { // traverse digits from the last element (least significant)
        // since we begin with the last digit, increasing that digit by one
        // results in overflow.  Therefore, all elements PRIOR to digits[0]
        // need to be considered since there may be additional nines between
        // digits[0], ... , digits[n].
        if (digits[i] == 9) {  
          digits[i] = 0;
        } else {  // current digit is not 9 so we can safely increment by one
          digits[i] += 1;
          return digits;
        }
      }
      // if the program runs to this point, each 9 is now a 0.
      // to get a correct solution, we need to add one more element with 
      // a value of zero AND set digits[0] to 1 (in the most significant position)
      // to account for the carry digit.
      digits.push_back(0);
      digits[0] = 1;
      return digits;
    }
};