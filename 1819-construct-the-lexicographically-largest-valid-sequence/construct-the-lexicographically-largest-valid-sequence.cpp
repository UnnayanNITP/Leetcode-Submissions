class Solution {
public:
    bool generateSequence(vector<int>& sequence, vector<bool>& used, int index, int n) {
        if (index == sequence.size()) return true;

        if (sequence[index] != 0) return generateSequence(sequence, used, index + 1, n);

        for (int num = n; num >= 1; --num) {
            int nextIndex = (num == 1) ? index : index + num;
            if (used[num] || (num > 1 && (nextIndex >= sequence.size() || sequence[nextIndex] != 0))) 
            continue;
            
            sequence[index] = sequence[nextIndex] = num;
            used[num] = true;

            if (generateSequence(sequence, used, index + 1, n)) return true;

            sequence[index] = sequence[nextIndex] = 0;
            used[num] = false;
        }
        
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        generateSequence(sequence, used, 0, n);
        return sequence;
    }
};