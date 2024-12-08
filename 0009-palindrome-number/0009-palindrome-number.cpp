class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string r = s;
        reverse(s.begin(),s.end());
        return (!r.compare(s));
    }
};