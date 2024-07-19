// class Solution {
// public:
//     vector<int> luckyNumbers(vector<vector<int>>& matrix) {
//         int min=0,index=0;bool ismin;
//         vector<int> num;
//         // min in row and max in col
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[i].size(); j++) {
//                 min=matrix[i][0];
//                 if (min > matrix[i][j]) {
//                     min = matrix[i][j];
//                     index = j;
//                     ismin = true;
//                 }

//                 for (int k = 0; k < matrix.size(); k++) {
//                         if (matrix[k][index] > min)
//                            {ismin =false;
//                              break;}
//                         }
//                     if(ismin)
//                     {
//                         num.push_back(min);
//                     }

//                     }
//         }
//                 return num;}
//             };
            
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> num;

        
        for (int i = 0; i < matrix.size(); i++) {
            int min = matrix[i][0];
            int index = 0;

            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    index = j;
                }
            }

            
            bool ismax = true;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][index] > min) {
                    ismax = false;
                    break;
                }
            }

            
            if (ismax) {
                num.push_back(min);
            }
        }

        return num;
    }
};

    