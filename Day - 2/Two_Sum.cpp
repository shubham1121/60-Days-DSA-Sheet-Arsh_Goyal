//T.C -: O(N*N) S.C-O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};
//T.C -: O(N) S.C-O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        vector<int>v;
        unordered_set<int>s;
        int find = -1;
        for(int i=0;i<a.size();i++)
        {
           if(s.find(target-a[i])!=s.end())
           {
               find = target-a[i];
               v.push_back(i);
               break;
           }
            else
            {
                s.insert(a[i]);
            }
        }
        for(int i=0;i<a.size();i++)
        {
            if(find==a[i])
            {v.push_back(i);break;}
        }
        return v;
    }
};