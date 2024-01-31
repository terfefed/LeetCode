class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> answer(n, 0);
        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temp[i] > temp[s.top()]) {
                int index = s.top();
                s.pop();
                answer[index] = i - index;
            }
            s.push(i);
        }

        return answer;
    }
};