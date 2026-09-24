class Solution {
public:
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while(!q.empty()) {

            int sz = q.size();

            vector<int> v;

            while(sz--) {
                TreeNode* node = q.front();
                q.pop();

                v.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            vector<int> sorted = v;
            sort(sorted.begin(), sorted.end());

            unordered_map<int,int> pos;

            for(int i = 0; i < v.size(); i++)
                pos[v[i]] = i;

            for(int i = 0; i < v.size(); i++) {

                if(v[i] == sorted[i])
                    continue;

                int j = pos[sorted[i]];

                swap(v[i], v[j]);

                pos[v[j]] = j;
                pos[v[i]] = i;

                ans++;
            }
        }

        return ans;
    }
};