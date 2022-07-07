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