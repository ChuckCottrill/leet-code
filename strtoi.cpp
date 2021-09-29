
// leetcode
// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.

*
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

build up the reverse integer one digit at a time.
While doing so, we can check beforehand whether or not appending another digit would cause overflow.
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        const int SPACE = ' ';
        const int MINUS = '-';
        const int PLUS  = '+';
        int sindx = 0;
        // std::cout << "s:" << s << " " << std::endl;
        // skip space(s)
        for( ; SPACE == s[sindx]; ) { sindx++; }
        // recognize sign and skip
        int sign = 1;
        if( MINUS == s[sindx] ) { sign = -1; sindx++; }
        else if( PLUS == s[sindx] ) { sign = 1; sindx++; }
        // result value
        unsigned int result = 0;
        // limit to string length
        int length = s.length();
        for( ; (sindx<length); ) {
            int digit = -1;
            switch( s[sindx] ) {
                case '0': { digit=0; break; }
                case '1': { digit=1; break; }
                case '2': { digit=2; break; }
                case '3': { digit=3; break; }
                case '4': { digit=4; break; }
                case '5': { digit=5; break; }
                case '6': { digit=6; break; }
                case '7': { digit=7; break; }
                case '8': { digit=8; break; }
                case '9': { digit=9; break; }
                default:  { digit=-1; break; }
            }
            // std::cout << "ch:" << s[sindx] << "=" << digit << std::endl;
            ++sindx;
            // check whether found end of digits
            if( digit < 0 ) break;
            // check whether overflow
            if( result >= INT_MAX/10 ) {
                if( result > INT_MAX/10 ) {
                    if( sign > 0 ) { return INT_MAX; }
                    if( sign < 0 ) { return INT_MIN; }
                }
                // if( result == INT_MAX/10 ) {
                if( (sign>0) && (digit > 7) ) { return INT_MAX; }
                if( (sign<0) && (digit > 8) ) { return INT_MIN; }
// if( (rev > INT_MAX/10) || (rev == INT_MAX/10 && pop > 7) ) return 0;
// if( (rev < INT_MIN/10) || (rev == INT_MIN/10 && pop < -8) ) return 0;
            }
            result = result * 10 + digit;
        }
        // handle sign
        result *= sign;
        return result;
    }
};

int
main()
{
    Solution* sol = new Solution();
    int result;
    result = sol->myAtoi("12345");
std::cout << "result:" << result << " " << std::endl;
    result = sol->myAtoi("     -54321   ");
std::cout << "result:" << result << " " << std::endl;
    result = sol->myAtoi(" 2147483647 ");
std::cout << "result:" << result << " " << std::endl;
    result = sol->myAtoi(" -2147483647 ");
std::cout << "result:" << result << " " << std::endl;
    result = sol->myAtoi(" 2147483648 ");
std::cout << "result:" << result << " " << std::endl;
    result = sol->myAtoi(" -2147483648 ");
std::cout << "result:" << result << " " << std::endl;
}

