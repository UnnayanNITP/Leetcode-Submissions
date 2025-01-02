class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // words (0 index array) and queries 2D
        // q[i] = [l1,r1]
        // find no of strings present l1 to r1 
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int n = words.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
            prefixSum[i + 1] = prefixSum[i] + 1;
        } else {
            prefixSum[i + 1] = prefixSum[i];
        }
    }

    vector<int> ans;
    for (const auto& query : queries) {
        int li = query[0];
        int ri = query[1];
        ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
    }

    return ans;
    }
};