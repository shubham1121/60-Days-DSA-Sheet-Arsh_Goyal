// T.C -: O(N*M) S.C -: O(1)
    class Solution {
public:
    
   static bool mycomparator(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),mycomparator);
        string ans="";
        int cnt = strs[0].length();
            for(int i=0;i<strs[0].size();i++)
            {   int j;
                for(j=0;j<strs.size();j++)
                {
                    if(strs[0][i]!=strs[j][i])
                    {
                        return ans;
                    }
                }
             if(j==strs.size())
             {
                 ans+=strs[0][i];
             }
            }
        return ans;
    }
};