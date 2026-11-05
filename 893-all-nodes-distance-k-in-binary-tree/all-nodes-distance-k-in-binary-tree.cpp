class Solution {
public:
    map<TreeNode*, TreeNode*> mp;

    void solve(TreeNode* root, TreeNode* par) {
        if(root == NULL) return;

        mp[root] = par;

        solve(root->left, root);
        solve(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root, NULL);

        queue<TreeNode*> q;
        set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            if(level == k) {
                vector<int> ans;

                while(!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }

                return ans;
            }

            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis.count(node->left)) {
                    q.push(node->left);
                    vis.insert(node->left);
                }

                if(node->right && !vis.count(node->right)) {
                    q.push(node->right);
                    vis.insert(node->right);
                }

                if(mp[node] && !vis.count(mp[node])) {
                    q.push(mp[node]);
                    vis.insert(mp[node]);
                }
            }

            level++;
        }

        return {};
    }
};