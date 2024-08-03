class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // target and arr length are equal
        // 1 step select non empty sub arr of arr and reverse
        // return true if sub(arr) = target
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        return target == arr;
    }
};