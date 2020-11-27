class Solution {
public:
    bool canPartition(vector<int>& ar) {
        int total=0;
        for(int i:ar)
            total+=i;
        
        if(total%2)
            return false;
        
        total>>=1;
        
        bool dp[ar.size()+1][total+1];
        
        for(int i=0;i<=ar.size();i++)
        {
            for(int j=0;j<=total;j++)
            {
                if(i==0&&j==0||j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=false;
                else
                {
                    dp[i][j]=dp[i-1][j];
                    if(j>=ar[i-1])
                        dp[i][j] = dp[i][j] || dp[i-1][j-ar[i-1]];
                }
            }
        }
        
        return dp[ar.size()][total];
    }
};