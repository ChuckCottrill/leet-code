
// leetcode
// Sqrt(x)
// https://leetcode.com/problems/sqrtx/

/*
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

*/

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        double result = 1.0;

        if( x < 2 ) {
            if( 0 == x ) return 0;
            if( 1 == x ) return 1;
            if( x < 0 ) return 0;
        }

HERE

        int pow = 1;
        for( pow = 1; 1<<pow < x; ) {
            if( 1<<(pow+1) > x ) {
                break;
            }
            ++pow;
        }
        for( z = pow; z < x; ) {
            if( pow+z+1 > 
            
        
        }

double pow = x;
        for( ; k != 0; ) {
        }

        return result;
    }
};

int
main()
{
    // double stuff[] = { 2.0, 3.0, 4.0 }
    Solution* sol = new Solution();
    double r;
    r = sol->myPow(2.0,-2);
    std::cout << "r:" << r << std::endl;
}





