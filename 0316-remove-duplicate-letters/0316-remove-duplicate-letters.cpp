class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stack;
        vector<int> last(26, 0), seen(26, 0);
        for (int i = 0; i < s.size(); i++) 
             last[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++) {
         char c = s[i];
        if (seen[c - 'a']) continue;
     while (!stack.empty() && c < stack.back() && 
        i < last[stack.back() - 'a']) {
      seen[stack.back() - 'a'] = 0;
        stack.pop_back();
      }
      stack.push_back(c);
       seen[c - 'a'] = 1;
        }   
        return stack;
    }
};