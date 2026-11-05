class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int ans = 0;

        while(!q.empty()) {
            int n = q.size();
            unsigned long long first = q.front().second;
            unsigned long long last = 0;

            for(int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= first;
                last = idx;

                if(node->left)
                    q.push({node->left, 2*idx+1});

                if(node->right)
                    q.push({node->right, 2*idx+2});
            }

            ans = max(ans, (int)(last+1));
        }

        return ans;
    }
};