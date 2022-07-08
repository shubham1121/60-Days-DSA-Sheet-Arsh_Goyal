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
//T.C -: O(n) S.C-: O(1) Two pointer approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size() && nums[i]!=0)
        {i++;}
        j=i+1;
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]==0)
            {
                if(nums[j]!=0)
                {
                    swap(nums[i],nums[j]);
                    i++;j++;
                }
                else
                {
                    j++;
                }
            }
            else
            {i++;}
        }
        
    }
};