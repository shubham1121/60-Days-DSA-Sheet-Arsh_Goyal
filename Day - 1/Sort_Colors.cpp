//T.C -: O(N) Simply counted 0's and 1's and then placed them accordingly
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0;
        for(auto x:nums)
        {
            if(x==0)
            {count0++;}
            else if(x==1)
            {count1++;}
        }
        int x=0;
        while(count0>0)
        {nums[x++]=0; count0--;}
        while(count1>0)
        {nums[x++]=1; count1--;}
        while(x<nums.size())
        {nums[x++]=2;}
    }
};