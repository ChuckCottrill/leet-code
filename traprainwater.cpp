

class Solution {
public:
    int trap(vector<int>& height) {
        int max_idx = 0, max_val = 0;
        int sum = 0;

        int n = height.size();
        for(int ix=0; ix < n; ix++) {
            if (height[ix] >= max_val) {
                max_val = height[ix];
                max_idx = ix;
            }
        }
        // left
        int lh = 0;
        for(int ix=0; ix < max_idx; ix++) {
            if (height[ix] < lh) {
                sum += lh - height[ix];
            } else {
                lh = height[ix];
            }
        }
        // right
        int rh = 0;
        for(int ix=n-1; ix >= max_idx; ix--) {
            if (height[ix] < rh) {
                sum += rh - height[ix];
            } else {
                rh = height[ix];
            }
        }
        return sum;
    }
};

