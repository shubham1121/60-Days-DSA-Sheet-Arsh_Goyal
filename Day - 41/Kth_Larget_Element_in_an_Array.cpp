// T.C -: O(N*LogK)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>>min_heap;
        for(int &temp : nums)
        {
            min_heap.push(temp);
            if(min_heap.size()>k) min_heap.pop();
        }
        return min_heap.top();
    }
};