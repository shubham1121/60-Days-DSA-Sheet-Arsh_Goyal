// T.C -: O(1) S.C -: O(1) use of log2()

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return floor(log2(n))==ceil(log2(n));
    }
};

// T.C -: O(1) S.C -: O(1) use of bit manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return ((n&(n-1))==0);
    }
};