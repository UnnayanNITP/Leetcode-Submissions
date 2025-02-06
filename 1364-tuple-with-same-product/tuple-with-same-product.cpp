class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int count = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        for (auto& [product, freq] : productCount) {
            if (freq > 1) {
                count += (freq * (freq - 1)) / 2 * 8;
            }
        }

        return count;
    }
};
