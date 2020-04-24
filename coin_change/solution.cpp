// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/809/
// Passes all tests and faster than 98% solutions
struct stackElement {
	int coinI;
	int amount;
};

class Solution {
private:
	vector<stackElement> stack;
	void backOnStack() {
		stack.pop_back();
				
		if(stack.size())
			stack.back().coinI++;
	}

public:
	int coinChange(vector<int>& coins, int amount) {
		if(amount == 0)
			return 0;

		sort(coins.begin(), coins.end(), std::greater<int>());

		int rval = -1;
		int coinsNum = coins.size();
		stack.resize(1);
		stack[0].coinI = 0;
		stack[0].amount = amount;

		while(auto stackSize = stack.size()) {
			auto& cur = stack.back();

			if(cur.coinI == coinsNum) {
				backOnStack();
				continue;
			}

			stackElement next;
			next.amount = cur.amount - coins[cur.coinI];

			if(next.amount > 0) {
				if( rval == -1 ||
					(
						// Check if we dont already have a better (less coins) solution
						(rval > stackSize + 1)
						&&
						// Check if its enough coins to beat current solution
						( (rval - stackSize) * coins[cur.coinI] ) >= cur.amount
					)
				  )
				{
					next.coinI = cur.coinI;
					stack.push_back(next);
					continue;
				} else {
					backOnStack();
					continue;
				}
			}

			if(next.amount == 0) {
				if(rval > stackSize || rval == -1)
					rval = stackSize;

				backOnStack();
				continue;
			}

			cur.coinI++;
		}

		return rval;
	}
};
