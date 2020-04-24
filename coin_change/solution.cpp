// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/
// Passes all tests and faster than 98% solutions
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

		while(true) {
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
				if( rval == -1 ||
					(
						// Check if we dont already have a better (less coins) solution
						(rval > stack.size() + 1)
						&&
						// Check if its enough coins to beat current solution
						( (rval - stack.size()) * coins[cur.coinI] ) >= cur.amount
					)
				  )
				{
					next.coinI = cur.coinI;
					stack.push_back(next);
					continue;
				} else {
					stack.pop_back();

					if(!stack.size())
						break;

					stack.back().coinI++;
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
