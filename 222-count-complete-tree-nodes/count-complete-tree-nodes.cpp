class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int h = 0;
        TreeNode* temp = root;

        while(temp->left) {
            h++;
            temp = temp->left;
        }

        int l = 0, r = (1 << h) - 1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            TreeNode* node = root;

            for(int i = h-1; i >= 0; i--) {
                if(mid & (1 << i))
                    node = node->right;
                else
                    node = node->left;
            }

            if(node) l = mid+1;
            else r = mid-1;
        }

        return (1 << h) - 1 + l;
    }
};