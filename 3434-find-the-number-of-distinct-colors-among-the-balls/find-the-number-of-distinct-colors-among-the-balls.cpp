class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;
        vector<int> result;
        int distinctColors = 0;
        
        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                if (--colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);
                    --distinctColors;
                }
            }
            if (++colorCount[color] == 1) {
                ++distinctColors;
            }
            ballColor[ball] = color;
            result.push_back(distinctColors);
        }
        return result;
    }
};
