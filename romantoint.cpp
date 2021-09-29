
// leetcode
// Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

/*
Given a roman numeral, convert it to an integer.

Roman numerals are represented by seven different symbols: { I, V, X, L, C, D, M }
Symbol  Value
I       1
V       5
X       10
L       50
C       100
D       500
M       1000

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written as IV.
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.

There are six instances where subtraction is used:
place I before V (5) and X (10) to make 4 and 9.
place X before L (50) and C (100) to make 40 and 90.
place C before D (500) and M (1000) to make 400 and 900.
*/



/*
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

// Roman to Integer (romanToInt)
// const int RNV_I = 1;
// const int RNV_V = 5;
// const int RNV_X = 10;
// const int RNV_L = 50;
// const int RNV_C = 100;
// const int RNV_D = 500;
// const int RNV_M = 1000;
// const int SPACE = ' ';
// const int MINUS = '-';
// const int PLUS  = '+';

class Solution {
private:
    const int RNV_I; // = 1;
    const int RNV_V; // = 5;
    const int RNV_X; // = 10;
    const int RNV_L; // = 50;
    const int RNV_C; // = 100;
    const int RNV_D; // = 500;
    const int RNV_M; // = 1000;
    const int SPACE; // = ' ';
    const int MINUS; // = '-';
    const int PLUS;  // = '+';

public:
    Solution() :
        RNV_I( 1),
        RNV_V( 5),
        RNV_X( 10),
        RNV_L( 50),
        RNV_C( 100),
        RNV_D( 500),
        RNV_M( 1000),
        SPACE( ' '),
        MINUS( '-'),
        PLUS ( '+')
    {
    }

    int romanToInt(string s) {
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
        int slen = s.length();
        for( ; (sindx<slen); ) {
            int digit = 0;
            int sym = s[sindx++];
            // lookahead?
            switch( sym ) {
                case 'I': {
                    digit = RNV_I;
                    // place I before V (5) and X (10) to make 4 and 9.
                    if ( sindx<slen ) {
                        int symnext = s[sindx];
                        if ( ('V' == symnext) || ('X' == symnext) ) { digit = -RNV_I; }
                    }
                    break;
                }
                case 'V': { digit = RNV_V; break; }
                case 'X': {
                    digit = RNV_X;
                    // place X before L (50) and C (100) to make 40 and 90.
                    if ( sindx<slen ) {
                        int symnext = s[sindx];
                        if ( ('L' == symnext) || ('C' == symnext) ) { digit = -RNV_X; }
                    }
                    break;
                }
                case 'L': { digit = RNV_L; break; }
                case 'C': {
                    digit = RNV_C;
                    // place C before D (500) and M (1000) to make 400 and 900.
                    if ( sindx<slen ) {
                        int symnext = s[sindx];
                        if ( ('D' == symnext) || ('M' == symnext) ) { digit = -RNV_C; }
                    }
                    break;
                }
                case 'D': { digit = RNV_D; break; }
                case 'M': { digit = RNV_M; break; }
                default:  { digit = 0; break; }
            }
            // if "IV" { digit = 4; }
            // if "IX" { digit = 9; }
            // if "XL" { digit = 40; }
            // if "XC" { digit = 90; }
            // if "CD" { digit = 400; }
            // if "CM" { digit = 900; }
            // check whether found end of roman numeral digits
            // if( 0 == digit ) break;
            result += digit;
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
    string ray[] = {
        "III",
        "LCX",
        "MIXCLV"
    };
    int raysize = sizeof(ray) / sizeof(ray[0]);
    int result;
    for( int idx = 0; idx < raysize; ++idx ) {
        result = sol->romanToInt(ray[idx]);
        std::cout << "rn:" << ray[idx] << " = " << result << " " << std::endl;
    }
}

