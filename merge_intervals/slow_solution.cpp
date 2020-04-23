// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/803/
// Valid (but slow) solution for non-sorted intervals (like [[1,4],[0,4]])
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> rval;

		if(intervals.size() == 0)
			return rval;

		std::sort(intervals.begin(), intervals.end(),
			[](auto a, auto b) { return a[0] < b[0];} );

		vector<int>* curOut = nullptr;

		for(auto& i: intervals) {
			if(!curOut || (*curOut)[1] < i[0]) {
				rval.push_back(i);
				curOut = &rval.back();
			} else {
				if((*curOut)[1] < i[1]) {
					(*curOut)[1] = i[1];
					if((*curOut)[0] > i[0])
						(*curOut)[0] = i[0];
				}
			}
		}

		return rval;
	}
};

