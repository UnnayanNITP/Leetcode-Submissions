

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a map to store height and corresponding name
        unordered_map<int, string> mp;
        vector<string> sortedNames;

        // Fill the map with heights and names
        for(int i = 0; i < heights.size(); i++) {
            mp[heights[i]] = names[i];
        }

        // Sort heights in descending order
        sort(heights.rbegin(), heights.rend());

        // Fill the sortedNames vector using sorted heights
        for(int i = 0; i < heights.size(); i++) {
            sortedNames.push_back(mp[heights[i]]);
        }

        return sortedNames;
    }
};
