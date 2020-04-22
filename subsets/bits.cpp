// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/
// Not my idea. Idea from 'Solution' section. My fast realization.

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> rval;
		auto s = nums.size();

		int intMax = -1;
		unsigned int max = *reinterpret_cast<unsigned int*>(&intMax);
		max >>= (sizeof(int) * 8 - s);

		rval.resize(max + 1);

		for(int i = 0; i <= max; i++)
			for(int j = 0; j < s; j++)
				if((i >> j) & 1)
					rval[i].push_back(nums[j]);

		return rval;
	}
};
