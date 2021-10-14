
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) { return nums.size(); }
        auto it = nums.begin();
        auto prev = *it;
        ++it;
        for( ; it != nums.end(); ) {
            if ( *it == prev) {
                nums.erase(it);
            }
            else {
                prev = *it;
                ++it;
            }
        }
        return nums.size();
    }
};

