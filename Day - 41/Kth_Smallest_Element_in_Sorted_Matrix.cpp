class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>max_heap;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                max_heap.push(matrix[i][j]);
                if(max_heap.size()>k)
                    max_heap.pop();
            }
        }
        return max_heap.top();
    }
};