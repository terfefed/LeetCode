#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap; 
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                return {numIndexMap[complement], i};
            }
            numIndexMap[nums[i]] = i; 
        }
        return {}; 
    }
};