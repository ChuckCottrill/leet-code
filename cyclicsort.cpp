
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cstdio>

#include <stdlib.h>

class Solution {
public:
    int
    firstMissingPositive(std::vector<int>& nums)
    {
        long n = nums.size();
        // Cyclic Sort by ignoring numbers which are less then 1 or greater than or equal to array length.
        // This is done because cyclic sort sorts an array in o(n) iff numbers are in a proper range.
        int ix = 0;
        while( ix < n ) {
            long correct = long(nums[ix]) - 1;
            if( (nums[ix] <= 0)
             || (nums[ix] > n)
             || (nums[ix] == nums[correct]) ) {
printf("ix: %d++\n",ix);
                ix++;
            }
            else {
                // swap nums[ix], nums[correct]
                // nums[ix], nums[correct] = nums[correct], nums[i]
                int a = nums[ix];
                int b = nums[correct];
printf("swap(%d,%d)\n",a,b);
                nums[correct] = a;
                nums[ix] = b;
		// Now if at any index ix the number present is not equal to ix+1 then return ix+1
            }
        }
        for ( ix = 0; ix < n; ++ix) {
            if( nums[ix] != ix+1 ) {
                return ix+1;
		// If all the numbers in the range are already in the array then just return the next number
            }
        }
        return n + 1;
    }
};

int
main()
{
    // int pre[] = {3,4,-1,1};
    int ray[] = {3,4,-1,1};
    int n = sizeof(ray) / sizeof(ray[0]);
    std::vector<int> vec(ray, ray+n);
    Solution solution = Solution();
    int v = solution.firstMissingPositive(vec);
    printf("v:%d\n",v);

    int ray2[] = {2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
    n = sizeof(ray2) / sizeof(ray2[0]);
    std::vector<int> vec2(ray2, ray2+n);
    v = solution.firstMissingPositive(vec2);
    printf("v:%d\n",v);
}
