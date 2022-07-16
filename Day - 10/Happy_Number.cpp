// T.C -: O(NLogN) S.C -: O(N)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>s;
        int temp=0;
        while(n!=1)
        { temp=0;
            if(s.find(n)!=s.end())
            {
                return false;   
            }
            s.insert(n);
            while(n>0)
            {
                temp+=(n%10)*(n%10);
                n/=10;
            }
          n=temp;
        }
        return true;
    }
};