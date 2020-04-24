// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/803/
// Valid (and 87% fast) solution for non-sorted intervals (like [[1,4],[0,4]])
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> rval;

		if(intervals.size() == 0)
			return rval;

		vector<vector<int>::size_type> idx;
		auto size = intervals.size();
		idx.resize(size);
		for(vector<int>::size_type i = 0; i < size; i++)
			idx[i] = i;

		std::sort(idx.begin(), idx.end(),
			[&intervals](auto a, auto b) { return intervals[a][0] < intervals[b][0];} );

		vector<int>* curOut = nullptr;

		for(auto i: idx) {
			if(!curOut || (*curOut)[1] < intervals[i][0]) {
				rval.push_back(intervals[i]);
				curOut = &rval.back();
			} else {
				if((*curOut)[1] < intervals[i][1]) {
					(*curOut)[1] = intervals[i][1];
					if((*curOut)[0] > intervals[i][0])
						(*curOut)[0] = intervals[i][0];
				}
			}
		}

		return rval;
	}
};
