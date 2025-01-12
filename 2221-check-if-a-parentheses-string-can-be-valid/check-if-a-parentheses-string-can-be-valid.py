class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 != 0:
            return False
        
        low, high = 0, 0
        for i in range(len(s)):
            if locked[i] == '1':
                if s[i] == '(':
                    low += 1
                    high += 1
                else:
                    low -= 1
                    high -= 1
            else:
                low -= 1
                high += 1
            
            low = max(low, 0)
            if high < 0:
                return False
        
        return low == 0
