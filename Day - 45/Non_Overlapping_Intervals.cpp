// Greedy
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        int prev = 0;
        int n = i.size();
        int ans=0;
        for(int curr=1;curr<n;curr++)
        {
            if(i[curr][0]<i[prev][1])
            {
                ans++;
                if(i[curr][1]<=i[prev][1])
                {
                    prev=curr;
                }
            }
            else
            {prev=curr;}
        }
        return ans;
    }
};