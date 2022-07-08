//T.C -: O(nlogn) S.C -: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto x:nums)
        {s.insert(x);}
        int size=0;
        for(auto x:s)
        {nums[size++]=x;}
        return size;
    }
};
//T.C -: O(n) S.C -: O(1) Two pointer approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(nums[i]!=nums[j])
            { i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};