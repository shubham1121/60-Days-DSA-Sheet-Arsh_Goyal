//T.C -: O(N) S.C -: O(1) Greedy Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        bool check=true;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=(goal-i))
            {check=true; goal = i;}
            else
            {check=false;}
        }
        return check;
    }
};