class Solution {
public:
    // int climbStairs(int n) {
    //     if(n<0) return 0;
    //     if(n==0) return 1;
    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
    int climbStairs(int n) {
        int dp[n+1]; //dp[i] represents the number of steps required to climb (i)th stair.
        dp[0]=0; // 0 number of 1 and 2 steps are req to reach at 0 stair.
        dp[1]=1; //1 number of 1 step is required to reach at stair 1.
        if(n>=2)
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {   
            dp[i]=dp[i-1]+dp[i-2]; 
        }
        return dp[n];
    }
};