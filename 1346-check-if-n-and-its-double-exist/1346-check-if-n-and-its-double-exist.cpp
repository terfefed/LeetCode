class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> abc;
        for(int i=0;i<arr.size();i++)
        {
            int doub = arr[i]*2;
            float half = arr[i]/2;
            if(abc.find(doub)!=abc.end() || (abc.find(half)!=abc.end() && arr[i]%2==0))
            {
                return true;
            }
            abc[arr[i]]=i;
        }
        return false;
    }
};