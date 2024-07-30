class Solution {
public:
    int minimumDeletions(string s) {
        int count_b = 0;
        int deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                count_b++;
            } else { // c == 'a'
                deletions = min(deletions + 1, count_b);
            }
        }

        return deletions;
    }
};
