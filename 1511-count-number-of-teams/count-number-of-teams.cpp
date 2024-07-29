class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;

       
        vector<int> greaterCount(n, 0);
        vector<int> lesserCount(n, 0);

      
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > rating[i]) {
                    greaterCount[i]++;
                } else if (rating[j] < rating[i]) {
                    lesserCount[i]++;
                }
            }
        }

       
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > rating[i]) {
                    result += greaterCount[j];
                } else if (rating[j] < rating[i]) {
                    result += lesserCount[j];
                }
            }
        }

        return result;
    }
};
