
// leetcode
// Super Pow (a, vector<int> b)
// https://leetcode.com/problems/super-pow/

/*
task is to calculate a^b mod 1337, where a is positive integer, b is extremely large positive integer provided as array of digits
constraints:
    1 <= a <= 231 - 1
    1 <= b.length <= 2000
    0 <= b[i] <= 9
    b does not contain leading zeros.
*/

#include <iostream>

class Solution {
    // const int Leet;
public:
    // Solution() : Leet(1337) { }
    int superPow(int a, vector<int>& b) {
        double result = 1.0;

HERE

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


