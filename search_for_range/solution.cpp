// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/802/

class Solution {
	int t;
	int left = -1, right = -1;

	void enlageToBoundries(vector<int>& nums) {
		while(left) {
			if(nums[left - 1] != t)
				break;
			
			left--;
		}

		int last = nums.size() - 1;
		while(right != last) {
			if(nums[right + 1] != t)
				break;
			
			right++;
		}
		
	}

	void find(vector<int>& nums, int start, int end) {
		int midIndex = start + (end - start) / 2;
		int midVal = nums[midIndex];
		
		if(midVal == t) {
			left = right = midIndex;
			enlageToBoundries(nums);
		} else if(midVal > t) {
			if(midIndex != end)
				find(nums, start, midIndex);
		} else { //midVal < t
			if(midIndex != start)
				find(nums, midIndex, end);
		}
	}

public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> rval;
		rval.resize(2, -1);

		if(nums.size() == 0)
			return rval;

		t = target;
		find(nums, 0, nums.size());
		rval[0] = left;
		rval[1] = right;
		return rval;
	}
};
