class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> a;
        for(int i=0;i<s.size();i++)
        {
            char target = s[i];
            if(a.find(target) != a.end())
            {
                return target;
            }
            a.insert(target);
        }
        return 'a';
    }
};