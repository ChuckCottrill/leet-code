
// leetcode
// Valid Parentheses
// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

/*
Given a string s, determine if it is valid.

A string s is valid if, starting with empty string t = "",

A string s is valid if, starting with an empty string t = "",
you can transform t into s after performing the following operation any number of times:

Insert string "abc" into any position in t.
More formally, t becomes tleft + "abc" + tright,
where t == tleft + tright. Note that tleft and tright may be empty.
Return true if s is a valid string, otherwise, return false
*/

class Solution {
private:
    string WORD;
public:
    Solution() : WORD("abc") { }
    bool isValid(string s) {
// bool valid = true;
        // how long is word?
        std::size_t wordlen = WORD.length();
        // copy(duplicate) string
        std::string str = s; // s.copy(s, s.length(), 0);

        std::size_t found;
        while( str.length()>0 ) {
            // check whether string contains WORD
            found = str.find(WORD);
            if ( found == string::npos ) { break; }
            // remove WORD from string
            str.erase(found,wordlen);
        }
        return (0 == str.length());
    }
};

