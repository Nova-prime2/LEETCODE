class Solution {
    int diameter = 0;

    int height(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = height(node->left);
        int right = height(node->right);

        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};