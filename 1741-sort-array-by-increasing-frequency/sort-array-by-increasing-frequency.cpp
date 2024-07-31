

// Comparator function
bool compare(int a, int b, unordered_map<int, int>& freq) {
    if (freq[a] == freq[b]) {
        return a > b; // Sort by value in descending order if frequencies are the same
    }
    return freq[a] < freq[b]; // Sort by frequency in ascending order
}

// Custom comparator wrapper for sort
struct Comparator {
    unordered_map<int, int>& freq;
    Comparator(unordered_map<int, int>& freq) : freq(freq) {}
    bool operator()(int a, int b) {
        return compare(a, b, freq);
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Count the frequency of each element
        for (int n : nums) {
            freq[n]++;
        }

        // Sort the array with the custom comparator
        sort(nums.begin(), nums.end(), Comparator(freq));

        return nums;
    }
};

