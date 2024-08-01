class Solution {
public:
    int countSeniors(vector<string>& details) {
        // zero indexed array of strings details
        // 1st 10 char phone number, M or F, next two age, last two seat alloted
        // return age > 60 people
        int t = 0;
        for (int i = 0; i < details.size(); i++) {

            if (details[i][11] >= '6' ) {
                {
                    if((details[i][11]=='6')&&(details[i][12]!='0'))
                    {
                        t++;
                    }
                    else if(details[i][11] > '6' )
                    t++;
                }
            }
        }
        return t;
    }
};