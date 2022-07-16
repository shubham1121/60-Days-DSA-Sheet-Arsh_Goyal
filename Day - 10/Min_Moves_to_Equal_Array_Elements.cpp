// T.C -: O(NLogN) S.C -: O(1) Sorting and then summing the diff between bigger elements with smallest element.
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=nums.size()-1;i>0;i--)
        {
            ans+=nums[i]-nums[0];
        }
        return ans;
    }
};
// T.C -: O(N) S.C -: O(1) 
// Let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;
// After, say m moves, we get all the numbers as x , and we will get the following equation.
//sum + m * (n - 1) = x * n
//x = minNum + m
//sum - minNum * n = m
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {total_sum+=nums[i];}
        return total_sum - (mini*n);
    }
};