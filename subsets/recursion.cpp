// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/

class Solution {
private:
    vector<vector<int>> rval;
    vector<int> stack;

    void step(const vector<int>& nums) {
        rval.push_back(stack);

        auto s = nums.size();

        vector<int> next;

        for(int i = 0; i < s; i++) {
            stack.push_back(nums[i]);

            next.clear();

            next.reserve(s - i - 1);
            for(int j = i + 1; j < s; j++)
                next.push_back(nums[j]);

            step(next);

            stack.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        stack.reserve(nums.size());
        step(nums);
        return std::move(rval);
    }
};
