

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        
        // Count the occurrences of each string in the array
        for (const auto& str : arr) {
            countMap[str]++;
        }

        // Find the k-th distinct string
        int distinctCount = 0;
        for (const auto& str : arr) {
            if (countMap[str] == 1) {
                distinctCount++;
                if (distinctCount == k) {
                    return str;
                }
            }
        }
        
        // If there are fewer than k distinct strings, return an empty string
        return "";
    }
};


