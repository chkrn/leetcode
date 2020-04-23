// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/803/
// Valid (and 86% fast) solution for non-sorted intervals (like [[1,4],[0,4]])
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> rval;

		if(intervals.size() == 0)
			return rval;

		vector<vector<int>*> ptrs;
		ptrs.reserve(intervals.size());
		for(auto& i: intervals)
			ptrs.push_back(&i);

		std::sort(ptrs.begin(), ptrs.end(),
			[](auto a, auto b) { return (*a)[0] < (*b)[0];} );

		vector<int>* curOut = nullptr;

		for(auto i: ptrs) {
			if(!curOut || (*curOut)[1] < (*i)[0]) {
				rval.push_back(*i);
				curOut = &rval.back();
			} else {
				if((*curOut)[1] < (*i)[1]) {
					(*curOut)[1] = (*i)[1];
					if((*curOut)[0] > (*i)[0])
						(*curOut)[0] = (*i)[0];
				}
			}
		}

		return rval;
	}
};
