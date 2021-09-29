
// leetcode
// Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
private:
    // const int LPAREN;
    // const int RPAREN;
    // const int LBRACKET;
    // const int RBRACKET;
    // const int LBRACE;
    // const int RBRACE;
public:
    // Solution() :
    //     LPAREN('('), RPAREN(')'),
    //     LBRACKET('['), RBRACKET(']'),
    //     LBRACE('{'), RBRACE('}')
    // {
    // }

    vector<string> generateParenthesis(int n) {

        vector<string> result;

        if( 0 == n ) { result.push_back(""); return result; }
        if( 1 == n ) { result.push_back("()"); return result; }

        // if( n > 1 )
        for( int closure = 0; closure < n; ++closure ) {
            for (string left: generateParenthesis(closure) ) {
                for (string right: generateParenthesis(n-1-closure) ) {
                    result.push_back("(" + left + ")" + right);
                }
            }
        }
// vector<string> child = generateParenthesis(n-1);
        return result;
    }
};



