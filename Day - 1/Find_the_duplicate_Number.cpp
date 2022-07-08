//T.C -: O(N), S.C -: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
        {mp[x]++;}
        int ans = 0;
        for(auto x:mp)
        {
            if(x.second>1)
            {ans=x.first; break;}
        }
        return ans;
    }
};

//T.C -: O(N), S.C -: O(1) But  Modified the array. Negative Marking Approach.
//Marked each of the values of nums and if an upcoming value is already -ve that
//means it was already marked by some earlier values that means current value is 
//duplicate. 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = -1;
        for(int i=0;i<nums.size();i++)
        {
            int temp = abs(nums[i]);
            if(nums[temp]<0)
            {
                ans = temp;
                break;
            }
            nums[temp]*=-1;
            
        }
        return ans;
    }
};

//T.C -: O(N), S.C -: O(1) Not Modified Array Floydd Warshal Algo (Slow fast pointer approach Cycle in a Linked list)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);
        slow = nums[0];
        while(slow!=fast)
        {slow=nums[slow]; fast = nums[fast];
        }
        return slow;
    }
};