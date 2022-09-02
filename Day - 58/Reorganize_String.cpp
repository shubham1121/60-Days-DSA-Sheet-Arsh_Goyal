// The most freq elements should pe placed alternatively first
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>umap;
        for(char &ch : s)
        {
            umap[ch]++;
        }
        priority_queue<pair<int,char>>max_heap;
        for(auto p:umap)
        {
            max_heap.push({p.second,p.first});
        }
        string res="";
        pair<int,char>block=max_heap.top();
        max_heap.pop();
        res+=block.second;
        block.first-=1;
        while(max_heap.size()>0)
        { pair<int,char> temp = max_heap.top();
          max_heap.pop();
          res+=temp.second;
          temp.first--;
         if(block.first>0)
         {
             max_heap.push(block);
         }
            block=temp;
        }
        return res.size()==s.size() ? res:"";
    }
};