

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // Vector to store all subarray sums
        vector<int> subarraySums;

        // Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }

        // Sort the subarray sums
       sort(subarraySums.begin(), subarraySums.end());

        // Calculate the sum of elements from the left-th to the right-th position
        int result = 0;
        const int MOD = 1e9 + 7;
        for (int i = left - 1; i < right; ++i) {
            result = (result + subarraySums[i]) % MOD;
        }

        return result;
    }
};

