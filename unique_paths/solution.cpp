// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/808/

#include <vector>

class Solution {
private:
    vector<int> cache;

    int& getCache(int m, int n) {
        if(m > n)
            return cache[100 * n + m];
        else
            return cache[100 * m + n];
    }

    int count(int m, int n) {
        if(m == 2)
            return n;

        if(n == 2)
            return m;

        int& cached = getCache(m, n);

        if(cached)
            return cached;

        return (cached = count(m - 1, n) + count(m, n - 1));
    }

public:
    int uniquePaths(int m, int n) {
        if(n == 1 || m == 1)
            return 1;

        cache.resize(100 * 100);

        return count(m, n);
    }
};
