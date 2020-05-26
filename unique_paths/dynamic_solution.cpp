class Solution {
	vector<vector<int>> cache;

	int f(int m, int n) {
		if(m == 1 || n == 1)
			return 1;

		if(cache[m - 1][n - 1])
			return cache[m - 1][n - 1];

		auto rval = f(m , n - 1) + f (m - 1, n);
		cache[n - 1][m - 1] = rval;
		cache[m - 1][n - 1] = rval;
		return rval;
	}

public:
	int uniquePaths(int m, int n) {
		auto max = std::max(m, n);
		cache.resize(max);
		for(auto& c : cache)
			c.resize(max, 0);

		return f(m, n);
	}
};
