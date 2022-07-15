//T.C -: O(N+M) S.C -: O(N+T)

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m>n)
            return "";
        unordered_map<char,int>mp;
        for(char &c : t)
        {mp[c]++;}
        int cnt = mp.size();
        int i=0,j=0;
        int len = INT_MAX;
        string ans="";
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    cnt--;
                }
            }

                while(cnt==0)
                {
                    if(len>j-i+1)
                    {
                        len=j-i+1;
                        ans=s.substr(i,len);
                    }
                    
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        {
                            cnt++;
                        }
                    }
                    i++;
                }
            j++;
        }
        return len!=INT_MAX ? ans : "" ;
    }
};