
class Solution {
public:
    int maxLength(const std::vector<std::string>& arr) {
        int result = 0;
        std::vector<std::unordered_set<char>> uniqueSets = {{}};

        for (const std::string& s : arr) {
            std::unordered_set<char> currentSet;

            // Check if the characters in the current string are unique
            bool isUnique = true;
            for (char ch : s) {
                if (currentSet.count(ch) > 0) {
                    isUnique = false;
                    break;
                }
                currentSet.insert(ch);
            }

            if (isUnique) {
                // Only consider strings with unique characters
                std::vector<std::unordered_set<char>> newSets;
                for (const auto& charSet : uniqueSets) {
                    // Check if the characters in the current string are also unique to the existing sets
                    std::unordered_set<char> combinedSet = charSet;
                    combinedSet.insert(currentSet.begin(), currentSet.end());

                    if (combinedSet.size() == charSet.size() + currentSet.size()) {
                        newSets.push_back(combinedSet);
                        result = std::max(result, static_cast<int>(combinedSet.size()));
                    }
                }
                uniqueSets.insert(uniqueSets.end(), newSets.begin(), newSets.end());
            }
        }

        return result;
    }
};
