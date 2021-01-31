class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        for(int j=0;j<N;j++)
        {
            for(int i=1;i<N;i++)
            mat[i][j]+=mat[i-1][j];
        }
        for(int i=0;i<N;i++)
        {
            for(int j=1;j<N;j++)
            mat[i][j]+=mat[i][j-1];
        }
        
        int maxi=INT_MIN;
        for(int i=K-1;i<N;i++)
        for(int j=K-1;j<N;j++)
        {
            if(i==K-1 && j==K-1)
            maxi=max(maxi,mat[i][j]);
            else if(j==K-1)
            maxi=max(maxi,mat[i][j]-mat[i-K][j]);
            else if(i==K-1)
            maxi=max(maxi,mat[i][j]-mat[i][j-K]);
            else
            maxi=max(maxi,mat[i][j]-mat[i-K][j]-mat[i][j-K]+mat[i-K][j-K]);
        }
        return maxi;
    }  
};