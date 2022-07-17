// T.C -: O(N) S.C -: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int t_sum =0;
        t_sum = (n*(n+1))/2;
       for(int i=0;i<n;i++)
       {
           sum+=nums[i];
       }
        return t_sum-sum;
    }
};