// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/
// WARNING! Solution is slow, doest not passes all tests.
struct stackElement {
	int coinI;
	int amount;
};

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if(amount == 0)
			return 0;

		sort(coins.begin(), coins.end(), std::greater<int>());

		int rval = -1;
		int coinsNum = coins.size();
		vector<stackElement> stack;
		stack.resize(1);
		stack[0].coinI = 0;
		stack[0].amount = amount;

		while(stack.size()) {
			auto& cur = stack.back();

			if(cur.coinI == coinsNum) {
				stack.pop_back();
				
				if(!stack.size())
					break;
				
				stack.back().coinI++;
				continue;
			}

			stackElement next;
			next.amount = cur.amount - coins[cur.coinI];

			if(next.amount > 0) {
				// Check if we already have not better path
				if(rval == -1 || rval > stack.size()) {
					next.coinI = 0;
					stack.push_back(next);
					continue;
				}
			}

			if(next.amount == 0) {
				if(rval > stack.size() || rval == -1)
					rval = stack.size();
				
				stack.pop_back();
				
				if(!stack.size())
					break;
				
				stack.back().coinI++;
				continue;
			}

			cur.coinI++;
		}

		return rval;
	}
};
