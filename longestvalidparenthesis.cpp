
class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> stack;
        stack.push(-1);
        int maxans = 0;
        for ( int idx = 0; idx < s.length(); idx++ ) {
        // for ( auto idx, ch : s ) {
            int ch = s[idx];
            switch ( ch ) {
                case '(': {
                    stack.push(idx);
                    break;
                }
                case ')': {
                    if (! stack.empty() ) {
                        stack.pop();
                    }
                    if ( stack.empty() ) {
                        stack.push(idx);
                    } else {
                        // if (! stack.empty() ) {
                        int tip = stack.top();
                        maxans = max( maxans, (idx - tip));
                        // }
                    }
                    break;
                }
            }
        }
        return maxans;
    }
};

