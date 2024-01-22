class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        vector<int> xyz(nums.size() + 1, 0); 
        vector<int> abc;
        abc.reserve(2);
        int zero, two;
        for (int i = 0; i < nums.size(); i++)
        {
            ++xyz[nums[i]];
            if (xyz[nums[i]] == 2)
                two = nums[i];
        }
        for (int i = 1; i < xyz.size(); i++) 
        { 
            if (xyz[i] == 0)
                zero = i;
        }
        abc.push_back(two);
        abc.push_back(zero);
        return abc;
    }
};
