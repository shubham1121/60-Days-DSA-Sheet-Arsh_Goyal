//T.C -: O(N) S.C -: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAns=INT_MIN;
        int l=0,r=height.size()-1;
        while(l<r)
        { 
            maxAns =  max(maxAns,(min(height[l],height[r]))*(r-l));
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {r--;}
        }
        return maxAns;
    }
};