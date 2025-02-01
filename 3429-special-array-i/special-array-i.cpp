class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // nums = [2,1,4]
        // if size = 1 return true
        // if size > 1
        // for i = 1 to size -2
        // if (nums[i-1]%2==0!=nums[i+1]%2==0)
        // return true
        
        if (nums.size()==1)
        {
            return true;
        }
        for (int i = 1;i<nums.size();i++)
            {
                if ((nums[i]%2==0)==(nums[i-1]%2==0))
                {
                   return false;
                }
            }
        return true;
    }
};