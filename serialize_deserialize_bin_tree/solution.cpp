// https://leetcode.com/explore/interview/card/top-interview-questions-medium/112/design/812/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void sStep(std::ostringstream& ss, TreeNode* node) {
        if(!node) {
            ss << "null ";
            return;
        }
        
        ss << node->val << " ";
        
        sStep(ss, node->left);
        sStep(ss, node->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream ss;
        sStep(ss, root);
        return ss.str();
    }
    
    void dStep(std::istringstream& ss, TreeNode* & pNode) {
        std::string s;
        ss >> s;
        if(s == "null") {
            pNode = nullptr;
            return;
        }
        pNode = new TreeNode();
        pNode->val = std::atoi(s.c_str());
        dStep(ss, pNode->left);
        dStep(ss, pNode->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        istringstream ss(data);
        dStep(ss, root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
