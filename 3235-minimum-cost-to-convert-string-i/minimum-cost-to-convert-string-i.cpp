

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        if (n != target.size()) {
            return -1; // Lengths do not match
        }

        // Map to store the conversion costs
        unordered_map<char, unordered_map<char, long long>> conversionCost;

        // Initialize the conversion cost map
        for (int i = 0; i < original.size(); ++i) {
            char o = original[i];
            char c = changed[i];
            long long z = cost[i];

            if (conversionCost[o].find(c) == conversionCost[o].end()) {
                conversionCost[o][c] = z;
            } else {
                conversionCost[o][c] = min(conversionCost[o][c], z);
            }
        }

        // Bellman-Ford to find all pairs minimum conversion cost
        for (char k = 'a'; k <= 'z'; ++k) {
            for (char i = 'a'; i <= 'z'; ++i) {
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (conversionCost[i].find(k) != conversionCost[i].end() &&
                        conversionCost[k].find(j) != conversionCost[k].end()) {
                        long long newCost = conversionCost[i][k] + conversionCost[k][j];
                        if (conversionCost[i].find(j) == conversionCost[i].end()) {
                            conversionCost[i][j] = newCost;
                        } else {
                            conversionCost[i][j] = min(conversionCost[i][j], newCost);
                        }
                    }
                }
            }
        }

        // dp[i] stores the minimum cost to convert source[0:i] to target[0:i]
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == LLONG_MAX) {
                continue;
            }

            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            } else if (conversionCost.find(source[i]) != conversionCost.end() &&
                       conversionCost[source[i]].find(target[i]) != conversionCost[source[i]].end()) {
                dp[i + 1] = min(dp[i + 1], dp[i] + conversionCost[source[i]][target[i]]);
            }
        }

        return dp[n] == LLONG_MAX ? -1 : dp[n];
    }
};

