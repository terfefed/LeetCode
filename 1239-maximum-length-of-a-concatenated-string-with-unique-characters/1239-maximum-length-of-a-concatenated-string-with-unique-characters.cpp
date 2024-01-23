class Solution {
public:
    int maxLength(const std::vector<std::string>& arr) {
        int result = 0;
        std::vector<std::bitset<26>> charOccurrences = {std::bitset<26>()};

        for (const std::string& s : arr) {
            std::bitset<26> currentSet;

            // Check if the characters in the current string are unique
            bool isUnique = true;
            for (char ch : s) {
                int index = ch - 'a';

                if (currentSet.test(index)) {
                    isUnique = false;
                    break;
                }

                currentSet.set(index);
            }

            if (isUnique) {
                // Only consider strings with unique characters
                std::vector<std::bitset<26>> newSets;
                for (const auto& charSet : charOccurrences) {
                    // Check if the characters in the current string are also unique to the existing sets
                    std::bitset<26> combinedSet = charSet | currentSet;

                    if (combinedSet.count() == charSet.count() + currentSet.count()) {
                        newSets.push_back(combinedSet);
                        result = std::max(result, static_cast<int>(combinedSet.count()));
                    }
                }
                charOccurrences.insert(charOccurrences.end(), newSets.begin(), newSets.end());
            }
        }

        return result;
    }
};
