// Memoization
// time complexity = O(n)
// space complexity = O(n)+O(n)
class Solution {
public:
    int solve(int ind, int dp[], vector<int>& cost)
    {
        if(ind==0)return dp[0]=0;
        if(ind==1)return dp[1]=0;
        if(dp[ind]!=-1)return dp[ind];
        dp[ind]=solve(ind-1, dp, cost)+cost[ind-1];
        if(ind>1)dp[ind]=min(dp[ind],solve(ind-2, dp, cost)+cost[ind-2]);
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+1];
        for(int i=0;i<=cost.size();i++)
        {
            dp[i]=-1;
        }
        return solve(cost.size(), dp, cost);
    }
};

// Tabulation
// time complexity = O(n)
// space complexity = O(n)
class Solution {
public:
    int solve(int ind, int dp[], vector<int>& cost)
    {
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=ind;i++)
        {
            dp[i]=dp[i-1]+cost[i-1];
            if(i>1)dp[i]=min(dp[i], dp[i-2]+cost[i-2]);
        }
        return dp[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+1];
        for(int i=0;i<=cost.size();i++)
        {
            dp[i]=-1;
        }
        return solve(cost.size(), dp, cost);
    }
};

// space optimization
// time complexity = O(n)
// space complexity = O(1)
class Solution {
public:
    int solve(int ind, vector<int>& cost)
    {
        int prev1=0;
        int prev2=0;
        for(int i=2;i<=ind;i++)
        {
            int cur=prev2+cost[i-1];
            if(i>1)cur=min(cur, prev1+cost[i-2]);
            prev1=prev2;
            prev2=cur;
        }
        return prev2;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost.size(), cost);
    }
};
