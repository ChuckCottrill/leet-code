

// leetcode
// Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

class Solution {
private:
    const int LPAREN;
    const int RPAREN;
    const int LBRACKET;
    const int RBRACKET;
    const int LBRACE;
    const int RBRACE;
public:
    Solution() :
        LPAREN('('), RPAREN(')'),
        LBRACKET('['), RBRACKET(']'),
        LBRACE('{'), RBRACE('}')
    {
    }
    bool isValid(string s) {
        // seen stack
        stack<int> seen;
        // vector<int> seen;
        int value;
        bool valid = true;
        int slen = s.length();
        for( int sindx = 0; sindx < slen; ++ sindx ) {
            int ch = s[sindx];
            switch(ch) {
                case '(': { seen.push(LPAREN); break; }
                case ')': { value = 0;
                    if( !seen.empty() ) { value = seen.top(); seen.pop(); };
                    valid = ( LPAREN   == value );
                    break;
                }
                case '[': { seen.push(LBRACKET); break; }
                case ']': { value = 0;
                    if( !seen.empty() ) { value = seen.top(); seen.pop(); };
                    valid = ( LBRACKET == value );
                    break;
                }
                case '{': { seen.push(LBRACE); break; }
                case '}': { value = 0;
                    if( !seen.empty() ) { value = seen.top(); seen.pop(); };
                    valid = ( LBRACE   == value );
                    break;
                }
                default: break;
            }
            if( ! valid ) {
                break;
            }
        }
        valid = valid && seen.empty();
        return valid;
    }
};


