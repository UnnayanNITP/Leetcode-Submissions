class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        rotations = 0
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                rotations += 1
        if nums[0] < nums[n - 1]:
            rotations += 1
        return rotations <= 1