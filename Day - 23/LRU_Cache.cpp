// T.C -: O(1) & S.C -: O(1)
class LRUCache{
    public:
    list<pair<int,int>>q;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            auto node=mp[key];
            int val=node->second;
            q.erase(node);
            mp.erase(key);
            q.push_front({key,val});
            mp[key]=q.begin();
            return val;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto node=mp[key];
            q.erase(node);
            mp.erase(key);
        }
        if(mp.size()==cap){
            auto node=q.end();
            node--;
            int k=node->first;
            mp.erase(k);
            q.pop_back();
        }
        q.push_front({key,value});
        mp[key]=q.begin();
    }
};