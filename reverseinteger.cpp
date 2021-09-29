
// leetcode
// Reverse Integer
// https://leetcode.com/problems/reverse-integer/

/*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

build up the reverse integer one digit at a time.
While doing so, we can check beforehand whether or not appending another digit would cause overflow.
*/

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while( 0 != x ) {
            int pop = x % 10;
            x /= 10;
            if( (rev > INT_MAX/10) || (rev == INT_MAX/10 && pop > 7) ) return 0;
            if( (rev < INT_MIN/10) || (rev == INT_MIN/10 && pop < -8) ) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

