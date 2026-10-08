class Solution {
public:

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* st = nullptr;

        // Build parent map and find start node
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                st = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from start
        unordered_set<TreeNode*> vis;
        q.push(st);
        vis.insert(st);

        int time = -1;

        while (!q.empty()) {

            int sz = q.size();
            time++;

            while (sz--) {

                TreeNode* node = q.front();
                q.pop();

                // left
                if (node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                // right
                if (node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                // parent
                if (parent[node] && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return time;
    }
};