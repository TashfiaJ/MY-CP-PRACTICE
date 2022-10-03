// Memoization
// time complexity=O(n)
// space complexity=O(n)+O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        if(n==0 || n==1)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=solve(n-1, dp)+solve(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};

// Tabulation
// time complexity=O(n)
// space complexity=O(n)+O(n)
class Solution {
public:
    int solve(int n, vector<int>& dp)
    {
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+2, -1);
        return solve(n, dp);
    }
};

// space optimized
// time complexity=O(n)
// space complexity=O(1)
class Solution {
public:
    int climbStairs(int n) {
        int pre1=1;
        int pre2=1;
        if(n==0 || n==1)return 1;
        for(int i=2;i<=n;i++)
        {
            int cur=pre1+pre2;
            pre2=pre1;
            pre1=cur;
        }
        return pre1;
    }
};
