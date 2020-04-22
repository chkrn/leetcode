// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/787/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> rval;

		if(!root)
			return rval;

		deque<TreeNode*> curLevel, nextLevel;
		curLevel.push_back(root);
		bool fwd = false;

		while(curLevel.size()) {
			vector<int> rvalElement;

			if(fwd)
				for(auto node: curLevel) {
					rvalElement.push_back(node->val);
					
					if(node->right)
						nextLevel.push_front(node->right);
					
					if(node->left)
						nextLevel.push_front(node->left);
				}
			else
				for(auto node: curLevel) {
					rvalElement.push_back(node->val);
					
					if(node->left)
						nextLevel.push_front(node->left);
										
					if(node->right)
						nextLevel.push_front(node->right);
				}

			fwd = !fwd;
			rval.push_back(std::move(rvalElement));
			curLevel = std::move(nextLevel);
		}

		return rval;
	}
};
