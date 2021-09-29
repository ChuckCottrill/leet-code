
// leetcode
// TwoSum
// https://leetcode.com/problems/two-sum/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class TwoSum {

public:
    vector<int>
    twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        map<int,int> numindex;
        for ( int idx = 0; idx < nums.size(); idx++ ) {
            int value = nums[idx];
            auto complement = target - value;
            if( auto it{ numindex.find(complement) }; it != std::end(numindex) ) {
                // use structured binding to get key and complement index
                auto[key,complementindex] { *it };
                result.push_back(complementindex);
                result.push_back(idx);
                return result;
            }
            numindex[value] = idx;
        }
        return result;
    }
}

