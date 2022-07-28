// T.C -: O(2^N) & S.C-: O(N) Recursive Solution
class Solution {
public:
    
    pair<int,int> getMinSum(int st,int end,vector<int>a)
    {
        if(st==end){
            return {a[st],0};
        }
        int maxLeaf = INT_MIN;
        int minSum = INT_MAX;
        for(int i=st;i<end;i++)
        {
            auto left = getMinSum(st,i,a);
            auto right  = getMinSum(i+1,end,a);
            maxLeaf = max(left.first,right.first);
            minSum = min(minSum,left.second+right.second+left.first*right.first);
        }
        return {maxLeaf,minSum};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        return getMinSum(0,arr.size()-1,arr).second;
    }
};

// T.C -: O(N*N) & S.C-: O(1) greedy approach select the min pro of two neighbours and combine them.
class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        while(arr.size()>1)
        { int mini = INT_MAX;
          int min_idx=-1;
            for(int i=1;i<arr.size();i++)
            {
                if(mini>arr[i]*arr[i-1])
                {
                    mini=arr[i]*arr[i-1];
                    min_idx= arr[i]<arr[i-1]? i : i-1;
                }
            }
         res += mini;
         arr.erase(arr.begin()+min_idx);
        }
        return res;
    }
}; 
