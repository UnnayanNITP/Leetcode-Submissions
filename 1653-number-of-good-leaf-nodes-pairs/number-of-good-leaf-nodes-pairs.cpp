

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
    
private:
    // Helper function to perform DFS and return distances of leaf nodes.
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        
        // If it's a leaf node, return a vector with a single element 1 (distance to itself).
        if (!node->left && !node->right) return {1};
        
        // Get the distances from left and right subtrees.
        vector<int> leftDistances = dfs(node->left, distance, count);
        vector<int> rightDistances = dfs(node->right, distance, count);
        
        // Count all pairs between left and right distances that are <= distance.
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    count++;
                }
            }
        }
        
        // Collect and return distances from current node to all leaf nodes.
        vector<int> allDistances;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) {
                allDistances.push_back(ld + 1);
            }
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) {
                allDistances.push_back(rd + 1);
            }
        }
        
        return allDistances;
    }
};

// Helper function to create a new tree node.
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

