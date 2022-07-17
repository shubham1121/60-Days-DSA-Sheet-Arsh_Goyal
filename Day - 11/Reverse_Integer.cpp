// T.C -: O(LogN) S.C -: O(1)
class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        long long temp = x;
        if(x>INT_MAX || x<INT_MIN)
        {return 0;}
        else if(x<0)
        {
            temp*=-1;
            isNeg=true;
        }
        
        long long rev=0;
        
        while(temp>0)
        {
            rev = rev*10 + temp%10;
            if(rev>INT_MAX || rev<INT_MIN)
            {
                return 0;
            }
            temp/=10;
        }
        return isNeg ? rev*=-1 : rev;
        
    }
};