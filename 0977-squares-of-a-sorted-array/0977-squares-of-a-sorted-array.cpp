class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            result.push_back(pow(nums[i],2));
        }
        sort(result.begin(),result.end());
        return result;
    }
};