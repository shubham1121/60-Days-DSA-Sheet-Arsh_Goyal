//T.C - : O(N) S.C -: O(1) Moore Voting Algo
class Solution {
public:
    int majorityElement(vector<int>& a) {
        int major = a[0];
        int count=1;
        for(int i=1;i<a.size();i++)
        {
            if(count==0)
            {
                count++;
                major = a[i];
            }
            else if(major==a[i])
            {
                count++;
            }
            else
            {count--;
             // major = a[i];
            }
        }
        return major;
    }
};