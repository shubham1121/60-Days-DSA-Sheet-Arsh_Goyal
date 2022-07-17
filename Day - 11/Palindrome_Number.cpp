// T.C -: O(LogN) S.C -: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long temp = x;
        long long rev=0;
        while(x>0)
        {
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev==temp;
    }
};