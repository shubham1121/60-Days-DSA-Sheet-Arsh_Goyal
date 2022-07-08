//T.C -: O(N) S.C-O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {maxP+=(prices[i]-prices[i-1]);}
        }
        return maxP;
    }
};