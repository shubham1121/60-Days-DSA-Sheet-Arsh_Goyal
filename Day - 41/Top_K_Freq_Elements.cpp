// T.C -: O(N*LogK)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap; // top freq k elements will be at last
        unordered_map<int,int>umap;
        for(int &temp: nums)
        {
            umap[temp]++;
        }
        for(auto &p : umap)
        {
            min_heap.push({p.second,p.first});
            if(min_heap.size()>k) min_heap.pop();
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};