

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Find the lowest common ancestor (LCA)
        TreeNode* lca = findLCA(root, startValue, destValue);

        // Find the path from LCA to startValue
        string pathToStart = "";
        findPath(lca, startValue, pathToStart);

        // Find the path from LCA to destValue
        string pathToDest = "";
        findPath(lca, destValue, pathToDest);

        // Transform path to start into 'U's
        for (char& c : pathToStart) {
            c = 'U';
        }

        // Combine paths
        return pathToStart + pathToDest;
    }

private:
    TreeNode* findLCA(TreeNode* root, int p, int q) {
        if (!root || root->val == p || root->val == q) {
            return root;
        }

        TreeNode* left = findLCA(root->left, p, q);
        TreeNode* right = findLCA(root->right, p, q);

        if (left && right) {
            return root;
        }
        return left ? left : right;
    }

    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) {
            return false;
        }
        if (root->val == value) {
            return true;
        }

        path.push_back('L');
        if (findPath(root->left, value, path)) {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, value, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};
