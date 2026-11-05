class Solution {
public:
    bool solve(TreeNode* root, long long mn, long long mx) {
        if(root == NULL) return true;

        if(root->val <= mn || root->val >= mx)
            return false;

        bool l = solve(root->left, mn, root->val);
        bool r = solve(root->right, root->val, mx);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};