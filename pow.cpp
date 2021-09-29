
// leetcode
// Pow(x, n)
// https://leetcode.com/problems/powx-n/

/*
Implement pow(x, n), which calculates x raised to the power n (i.e. x^n)
*/

#include <iostream>

class Solution {
public:
    // Solution() : WORD("abc") { }
    double myPow(double x, int n) {
        double result = 1.0;
        double pow = x;
        int sign = 1;
        int k = n;

        // std::cout << "n:" << n << std::endl;
        if( 0 == n ) { return 1.0; }
        if( n < 0 ) {
            sign = -1;
            // cannot take reciprocal of 0.0
            if( 0.0 == pow ) { return 0.0; }
            pow = 1/pow;
        } 
        // std::cout << "pow:" << pow << std::endl;

        for( ; k != 0; ) {
std::cout << "k:" << k << std::endl;
            if( 0 != (k % 2) ) {
                result = result * pow;
std::cout << "pow:" << pow << ",r:" << result << std::endl;
            }
            pow = pow*pow;
std::cout << "pow^k:" << pow << "^" << k << std::endl;
            k /= 2;
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

