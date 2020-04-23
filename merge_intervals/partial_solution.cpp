// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/803/
// WARNING! Simple solution for sorted intervals. Does not passes all tests.

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> rval;

		if(intervals.size() == 0)
			return rval;

		vector<int>* curOut = nullptr;

		for(auto& i: intervals) {
			if(!curOut || (*curOut)[1] < i[0]) {
				rval.push_back(i);
				curOut = &rval.back();
			} else
				(*curOut)[1] = i[1];
		}

		return rval;
	}
};
