// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         // distance of pair a and b = abs a&b
//         // return kth smallest distance among all pairs
//         // nums = [1,3,1] k=1
        
//         // find abs diff between each pair 
//         // for() -> diff -> vector -> sort ->
        
        
//         int a=0; vector<int> num;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 a=abs(nums[i]-nums[j]);
//                 num.push_back(a);
//             }
//         }
//         sort(num.begin(),num.end());
//         return num[k-1];

//     }
// };

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array first

        int left = 0, right = nums[nums.size() - 1] - nums[0];
        
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0, j = 0;

            // Count how many pairs have a distance <= mid
            for (int i = 0; i < nums.size(); i++) {
                while (j < nums.size() && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
