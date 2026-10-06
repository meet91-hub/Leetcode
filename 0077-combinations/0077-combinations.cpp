class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> chosen;        
        function<void(int)> pick = [&](int start) {
        if (chosen.size() == k) {
            result.push_back(chosen);
            return;
            }
            for (int num = start; num <= n; num++) {
                chosen.push_back(num);       
                pick(num + 1);                 
                chosen.pop_back();             
            }
        };
        pick(1);
        return result;
    }
};