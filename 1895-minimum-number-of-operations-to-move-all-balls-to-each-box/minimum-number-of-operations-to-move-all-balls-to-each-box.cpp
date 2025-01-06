class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        int balls = 0, moves = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += moves;
            if (boxes[i] == '1') balls++;
            moves += balls;
        }
        
        balls = 0, moves = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += moves;
            if (boxes[i] == '1') balls++;
            moves += balls;
        }
        
        return answer;
    }
};
