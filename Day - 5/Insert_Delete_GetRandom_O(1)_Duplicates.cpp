class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }

    bool insert(int val) {
        auto result = m.find(val) == m.end();
        
        m[val]++;
        nums.push_back(val);
        return result;
    }

    bool remove(int val) {
        auto result = m.find(val) != m.end();
        if(result)
        {
            auto it = nums.begin();
            for(;it!=nums.end();it++)
            {
                if(*it==val)
                {
                    break;
                }
            }
            if(it!=nums.end())
            {
                nums.erase(it);
            }
            if(m[val]==1)
            {m.erase(val);}
            else
            {
                m[val]--;
            }
        }
        return result;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};
