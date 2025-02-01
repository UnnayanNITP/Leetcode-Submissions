class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        bad_indices = []  # Not used in the optimized solution
        n = len(nums)
        pref_sum = [0] * n
        for i in range(1, n):
            pref_sum[i] = pref_sum[i - 1]
            if nums[i - 1] % 2 == nums[i] % 2:
                pref_sum[i] += 1

        qn = len(queries)
        ans = [True] * qn

        if n == 1:
            return ans

        for i in range(qn):
            u = queries[i][0]
            v = queries[i][1]
            count = pref_sum[v] - pref_sum[u]  # Corrected indexing for prefix sum
            ans[i] = count == 0  # Simplified condition
            
        return ans