class Solution {
public:
    void generateHappyStrings(int n, string &current, vector<string> &happyStrings, char lastChar) {
        if (current.length() == n) {
            happyStrings.push_back(current);
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lastChar) {
                current.push_back(ch);
                generateHappyStrings(n, current, happyStrings, ch);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current = "";
        generateHappyStrings(n, current, happyStrings, '\0');
        if (k > happyStrings.size()) return "";
        return happyStrings[k - 1];
    }
};