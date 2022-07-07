//T.C -: O(n) S.C-: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v;
        for(auto x:nums)
        {
            if(x!=0)
            {v.push_back(x);}
        }
        int k=0;
        for(auto x:v)
        {
            nums[k++] = x;
        }
        while(k<nums.size())
        {
            nums[k++]=0;
        }
    }
};