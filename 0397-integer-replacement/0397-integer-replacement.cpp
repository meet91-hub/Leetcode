class Solution {
public:
    int integerReplacement(int n) {
    long long num = n;
        return helper(num);
    }
private:
     int helper(long long n) {
    if (n == 1) return 0;
      if (n % 2 == 0) return 1 + helper(n/2);
    if (n == 3 || n % 4 == 1) return 1 + helper(n-1);
     return 1 + helper(n+1);
    }
};