// Greedily select the min cost ballon to remove first
class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        char prev = '*';
        int costp = 0;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(prev==s[i])
            {
                if(costp<cost[i])
                {
                    ans+=costp;
                    costp=cost[i];
                }
                else
                {
                    ans+=cost[i];
                }
            }
            else
            {
                prev=s[i];
                costp=cost[i];
            }
        }
        return ans;
    }
};