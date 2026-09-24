class Solution {
public:

    TreeNode* solve(int pl, int pr, int postl, int postr,
                    vector<int>& preorder, vector<int>& postorder) {

        if(pl > pr)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pl]);

        if(pl == pr)
            return root;

        // preorder[pl+1] is left subtree root
        int x = preorder[pl+1];

        int idx = postl;

        while(postorder[idx] != x)
            idx++;

        // number of nodes in left subtree
        int len = idx - postl + 1;

        root->left = solve(
            pl + 1,
            pl + len,
            postl,
            idx,
            preorder,
            postorder
        );

        root->right = solve(
            pl + len + 1,
            pr,
            idx + 1,
            postr - 1,
            preorder,
            postorder
        );

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        return solve(0, n-1, 0, n-1, preorder, postorder);
    }
};