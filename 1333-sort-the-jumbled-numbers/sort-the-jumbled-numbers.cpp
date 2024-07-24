#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    // Function to compute the mapped value of a number
    int computeMappedValue(int num, const vector<int>& mapping) {
        string numStr = to_string(num);
        string mappedStr;
        for (char ch : numStr) {
            int digit = ch - '0';
            mappedStr += to_string(mapping[digit]);
        }
        return stoi(mappedStr);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Vector of pairs (mapped value, original value) for sorting
       vector<pair<int, int>> mappedValues;
        for (int num : nums) {
            int mappedValue = computeMappedValue(num, mapping);
            mappedValues.emplace_back(mappedValue, num);
        }

        // Sort the pairs based on mapped values (first element of pair)
        sort(mappedValues.begin(), mappedValues.end(), 
                  [](const pair<int, int>& a, const pair<int, int>& b) {
                      return a.first < b.first;
                  });

        // Extract the sorted numbers from the pairs
        vector<int> result;
        for (const auto& pair : mappedValues) {
            result.push_back(pair.second);
        }

        return result;
    }
};
