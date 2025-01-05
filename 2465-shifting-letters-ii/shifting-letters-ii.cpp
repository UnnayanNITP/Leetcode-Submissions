#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> cumulative(n + 1, 0);
        
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int delta = (direction == 1) ? 1 : -1;
            cumulative[start] += delta;
            cumulative[end + 1] -= delta;
        }
        
        int netShift = 0;
        for (int i = 0; i < n; ++i) {
            netShift += cumulative[i];
            int shiftValue = (s[i] - 'a' + netShift) % 26;
            if (shiftValue < 0) shiftValue += 26;
            s[i] = 'a' + shiftValue;
        }
        
        return s;
    }
};
