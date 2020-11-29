int maxSubarraySum(int arr[], int n){
    int ans=arr[0],sum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(sum<0)
        sum=0;
        sum+=arr[i];
        ans=max(ans,sum);
    }
    return max(ans,sum);
}