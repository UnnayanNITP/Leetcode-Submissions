class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // 
        
        unordered_map<string,int> m;
        vector<string> v;
        // for(int i=0;i<arr.size();i++)
        // {
        //     if(m.find(arr[i])==m.end())
        //     {
        //         m[arr[i]]=1;
                
        //     }
        //     else if(m.find(arr[i])!=m.end())
        //     m[arr[i]]++;
        // }
        for (int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        // for(auto it=m.begin();it!=m.end();it++)
        // {
        //     if(it->second == 1)
        //     {
        //         v.push_back(it->first);
        //     }
        // }
        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]]==1)
            v.push_back(arr[i]);
        }
        if(v.size()>=k)
        return v[k-1];
        else
        return "";
    }
};